/************************************************************************************
 * Name ............ : io.h
 * Author .......... : MLasserre
 ***********************************************************************************/

#ifndef IO_H
#define IO_H

/* Function for writing to a file */
void write_data(const char* filename, int n, const real* tt, real** numerical);

void scan_real(real* in);

#endif /* IO_H */
