void inline init_histogram ( Histogram &histogram ) { 
    histogram.nBarsSize = 0;
    histogram.BarNames = 0;
    histogram.Bars = 0;
    histogram.chBlock = '#';
    histogram.nMaxBar = 1;
    histogram.bAscending = true;
}

void inline destroy_histogram ( Histogram &histogram ) {
    if ( histogram.nBarsSize ) {
        delete[] histogram.BarNames;
        histogram.BarNames = 0;
        delete[] histogram.Bars;
        histogram.Bars = 0;
    }
    histogram.nMaxBar = 1;
}