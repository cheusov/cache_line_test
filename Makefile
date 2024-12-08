PROG        =	cache_line_test
SRCS        =	cache_line_test.c get_time.c

WARNS       =	4

COPTS      ?=	-O2 -g

CACHE_LINE ?=	64 # change according to your hardware

CFLAGS     +=	-DCACHE_LINE=${CACHE_LINE}

.include <mkc.mk>
