# XF Ports

## Introduction
An XF (execution framework) consist of a view classes which some need to be adjusted
when used on another platform.

Following you will find a list of classes which may be adjusted/reimplemented when
changing to another platform/environment:
 - `XF`
 - `ResourceFactory`
 - `TimeoutManager`
 - `Dispatcher`
 - `EventQueue`
 - `Thread`
 - `Mutex`

These classes are also named `port classes` because they can be ported to another
platform. All port classes can be found in the _port_ folder whereas every port is
located in a separate folder.

Every port may pick some default implementation classes from the _default_ folders
also located in the _port_ folder.

In case you are going to implement an OS-less XF (hence an IDF) usually, you do not
need to implement the classes `Thread` and `Mutex`.

## Default Port Classes
There are already some default port class implementations present. You can find
them in the `default` folder and may suit your needs for a first version
of your XF. These default port classes are platform independent and can be 
used by any port implementation.

## Default Platform Classes
Some classes depent on external resources like for example an OS. These
classes are located in the _default-&lt;platform&gt;_ specific folders. Currently,
the following default platfroms are available:

| Platform | Folder | Description |
|--|--|--|
| CMSIS-OS | [default-cmsis-os](./default-cmsis-os) | CMSIS-OS abstraction layer |
| IDF | [default-idf](./default-idf) | Interrupt driven framework |
| QT | [default-qt](./default-qt) | Qt library |

## Port Folder Structure
In case you want to add support for another platform to the XF, you need to add a
subfolder to the _port_ folder and put the port class files in there. Best is to
take an already present port which is most similar to what you need, rename it and
start adaption of these files.

You may also mix-up you port with classes from the _default_, _default-&lt;platform&gt;_
folder and your custom folder (or even reference classes from other ports).

## Available Ports

Here is a list of currently available ports:

| Port Name | OS | Platform | Folder Name | Description |
|--|--|--|--|--|
| PORT_IDF_QT | Qt (IDF) | Qt library based implementation | idf-qt | XF support for OS X, Linux and Windows |
| PORT_IDF_STM32CUBE | Bare-Metal (IDF) | STM32CubeMX based port | idf-stm32cube | XF for ARM Cortex based microcontrollers from STMicroelectronics |
| PORT_STM32CUBE_CMSIS_FREERTOS | CMSIS OS (FreeRTOS) | Any platform supporting CMSIS OS | stm32cube-cmsis-freertos | FreeRTOS based port |
| PORT_ACTIVE_QT | Qt multi-thread | Qt library based implementation | active-qt | XF support for OS X, Linux and Windows (multi-thread) |
