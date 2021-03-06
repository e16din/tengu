# LoRedis

[English description](README.md)

LoRedis - это часть проекта [**Тэнгу**](https://github.com/unclesal/tengu/blob/master/README.ru.md).
Еще одна "легковесная" C++ обертка для hiredis, стандартной C API библиотеки
замечательного in-memory хранилища данных [Redis](https://redis.io)

## Уже есть несколько [C++ клиентских библиотек](https://redis.io/clients#c--) для редиса. Зачем нужна "еще одна"?

Цель создания данной библиотеки - это работа в качестве механизма сообщений в мульти-агентной среде, в условиях ограничения 
на время выполнения. Никто никого не ждет, сообщили - и едем дальше.

Библиотеки, конечно же, есть. И когда мне понадобилось работать с редисом, я стал их смотреть. Некоторые вообще не работали,
потому что не соответствовали сегодняшней версии редиса. Некоторые работали и имели интереснейшую реализацию, 
но при этом не имели ни документации, ни комментариев в исходниках, ни примеров. Я не знаю, как работать с 
такими текстами.

В итоге мне оказалось проще написать заново. 

Вообще говоря, **LoRedis** является частью большого проекта Tengu, посвященного научным исследованиям в области искусственного 
интеллекта. Но Вы можете использовать данную библиотеку и отдельно, самостоятельно, так, как оно Вам заблагорассудится - в рамках 
терминов свободной лицензии GPLv3.

## В чем особенности данной реализации?

- Ассинхронность, исключая специально оговоренные методы. 
- Реализована как Qt объект, взаимодействие происходит с использованием Qt механизма сигналов-слотов.
- Имеет возможность работать без цикла событий Qt. В тех случаях, когда нет смысла создавать QApplication,
можно обойтись одним только libevent и обработкой событий на основе callback-функций. Libevent имеет приоритет,
если установлен "реактор" libevent, то сигналы Qt генерироваться не будут.
- Содержит всего 3 файла исходников и может быть добавлена в любой проект напрямую, без использования
статических или динамических библиотек.

## Как собрать?

Для сборки нужны **libevent-dev** ну и сам **libhiredis-dev**.

Процесс сборки стандартный для qmake. Сначала нужно собрать саму библиотеку (каталог **src** ).

```
qmake
make
```

При желании можно сделать 

```
make install
```

В таком случае библиотека будет установлена в /usr/local

Далее, при желании, можно сделать все то же самое для каталога **examples**. Правда, там уже устанавливать 
будет нечего и make install не предусмотрена, это - только для посмотреть-попробовать.

## Как использовать?


```C++
// Для начала нужно создать объект и подцепить собственные обработчики его сигналов.
LoRedis * redis = new LoRedis();
QObject::connect( redis, SIGNAL( signalConnected() ), this, SLOT( onConnected()) );
QObject::connect( redis, SIGNAL( signalDisconnected() ), this, SLOT( onDisconnected()) );
QObject::connect( redis, SIGNAL( signalError(QString) ), this, SLOT( onError(QString)) );

// Остальные сигналы, они там еще есть, см. src/LoRedis.h и/или examples/RedisTester.cpp
// QObject::connect( ... ); 

// Функция connect() запускает внутренний цикл обработки событий.
redis->connect();

// После чего можно чего-нибудь с ним делать, только не забывая при этом, что бОльшая
// часть функций ассинхронная и результат выполнения будет - через сигналы, а не 
// прямо в тексте программы.

redis->set( "VariableName", "VariableValue" );
redis->publish( "ChannelName", "Текст сообщения" );

// Синхронный вариант. Вернет результат непосредственно здесь. Однако сигнал
// при этом - все равно возникнет.

QVariant val = redis->get_sync("VariableName");

```
Использование без Qt, через класс реакций и callback-процедуры:

```C++
#include "LoRedisReactor.h"
class MyClass : public LoRedisReactor {
    MyClass::MyClass() {
        LoRedis * redis = new LoRedis( this );
    };
};

```

