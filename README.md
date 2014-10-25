Washing Machine Firmware
========================

Yes, seriously. This will hopefully be firmware for a real, live washing machine
at some point.

Why?
----

I've always wanted to know what goes into the process of writing firmware for a
"boring" device like a washing machine or a microwave or whatever. As with
everything else I've ever been curious about, I figured the best way to find out
was just to jump right in without doing any research.

I'm hoping that I'll learn some stuff about good architecture and UI/UX for
mostly unattended devices. If the software itself ends up being useful, that's
just a bonus.

Plans
-----

I want to have a way to load programs into the machine, to tell it how to run.
Right now this is compiled into the binary, and this might be the best way to do
it, as it means there are no dynamic memory allocations. This is important for a
device that has to be rock-solid and run completely unsupervised.

The code has to run on a tiny, tiny little chip. If possible, an 8-bit micro.
This might balloon out to a 32-bit micro if I want to add any kind of remote
monitoring or command interface. That could be optional though, and I'd like it
if the core of the application could run on an ATmega or ATtiny chip.

Building
--------

```
$ make
cc    -c -o step.o step.c
cc    -c -o machine.o machine.c
cc     main.c step.o machine.o   -o main
```

Building for a micro
--------------------

You're going to need an `avr-gcc` toolchain to do this. If you're on a mac, the
easiest way to get this set up is to use [crosspack](http://www.obdev.at/products/crosspack/index.html).

If you're on another platform, you're kind of on your own. If/when you get a
toolchain set up, let me know how you went and I'll add some information here.

```
$ make -f Makefile.avr hex
```

Running
-------

```
$ ./main
PROGRAM:

[00] PING 0
[01] HEAT 30
[02] FILL 50
[03] WAIT 15
[04] WASH 25
[05] WAIT 15

INITIALISING MACHINE...
MACHINE INTIALISED!

RUNNING PROGRAM...

[00] PING 0
---- MACHINE STATE: HEAT=0, WATER=0, MODE=0, SPEED=0

[01] HEAT 30
---- MACHINE STATE: HEAT=30, WATER=0, MODE=0, SPEED=0

[02] FILL 50
---- MACHINE STATE: HEAT=30, WATER=50, MODE=0, SPEED=0

[03] WAIT 15
---- MACHINE STATE: HEAT=30, WATER=50, MODE=0, SPEED=0

[04] WASH 25
---- MACHINE STATE: HEAT=30, WATER=50, MODE=1, SPEED=25

[05] WAIT 15
---- MACHINE STATE: HEAT=30, WATER=50, MODE=1, SPEED=25

PROGRAM COMPLETE!
```

License
-------

3-clause BSD. A copy is included with the source.

Contact
-------

* GitHub ([deoxxa](http://github.com/deoxxa))
* Twitter ([@deoxxa](http://twitter.com/deoxxa))
* ADN ([@deoxxa](https://alpha.app.net/deoxxa))
* Email ([deoxxa@fknsrs.biz](mailto:deoxxa@fknsrs.biz))
