#include <stdio.h>
#include <stdlib.h>
#include <inttypes.h>
#include <sys/time.h>
#include <sys/resource.h>

#include "get_time.h"

uint64_t current_time(void) {
	struct timeval time;
	if (gettimeofday(&time, NULL)) {
		perror("gettimeofday(2) failed");
		exit(1);
	}
	return time.tv_sec * 1000000uL + time.tv_usec;
}

uint64_t user_time(void) {
	struct rusage r_usage;
	if (getrusage(RUSAGE_SELF, &r_usage)) {
		perror("getrusage(2) failed");
		exit(1);
	}
	return r_usage.ru_utime.tv_sec * 1000000uL + r_usage.ru_utime.tv_usec;
}
