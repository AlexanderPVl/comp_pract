#pragma once

typedef struct {
	char **BarNames;
	int *Bars;
	int nBarsSize;
	char chBlock;
	int nMaxBar;
    bool bAscending;
} Histogram;

void inline init_histogram( Histogram &histogram );
void inline destroy_histogram( Histogram &histogram );
void print_histogram( const Histogram &histogram );
void add_block( Histogram &histogram, const char *strName );
void get_array( Histogram &histogram );

#include "histogram.inl"