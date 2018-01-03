/*
Copyright (C) 2006 Pedro Felzenszwalb

This program is free software; you can redistribute it and/or modify
it under the terms of the GNU General Public License as published by
the Free Software Foundation; either version 2 of the License, or
(at your option) any later version.

This program is distributed in the hope that it will be useful,
but WITHOUT ANY WARRANTY; without even the implied warranty of
MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
GNU General Public License for more details.

You should have received a copy of the GNU General Public License
along with this program; if not, write to the Free Software
Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307 USA
*/

#include <cstdio>
#include <cstdlib>
#include <cstdint>
#include "mex.h"
//#include "image.h"
#include "misc.h"
//#include "pnmfile.h"
#include "segment_image_label.h"

void mexFunction(
	int nargout,
	mxArray *out[],
	int nargin,
	const mxArray *in[]
	)
{
	//if (argc != 6) {
	//	fprintf(stderr, "usage: %s sigma k min input(ppm) output(ppm)\n", argv[0]);
	//	return 1;
	//}
	//printf("entering!\n");
	if (nargin != 5 )
		mexErrMsgTxt("5 parameters are required: input data, neighborhood size, regularization, and min size [required regions]!");
	if(!mxIsDouble(in[0]) || !mxIsDouble(in[1]) || !mxIsDouble(in[2]) || !mxIsDouble(in[3]))
		mexErrMsgTxt("All input should be double type!");
	if(nargout != 1)
		mexErrMsgTxt("only 1 output is allowed!");
	double k, *imdata;
	int min_size, width, height, nchs, num_regions=-1,radius;
	const int *dims_imdata;
	uint32_t *label=NULL;
	//parse input data
	int ndims = (int)mxGetNumberOfDimensions(in[0]);
	if(ndims !=2 && ndims !=3)
		mexErrMsgTxt("Wrong input image data!");

	dims_imdata = mxGetDimensions(in[0]);
	height = dims_imdata[0];
	width = dims_imdata[1];
	if(ndims==3)
		nchs = dims_imdata[2];
	else
		nchs = 1;
	imdata =  mxGetPr(in[0]);
	//printf("height=%d width=%d nchs=%d\n",height,width,nchs);
	radius =(int) mxGetScalar(in[1]);
	k = mxGetScalar(in[2]);
	min_size =(int) mxGetScalar(in[3]);
	
	num_regions = (int) mxGetScalar(in[4]);
	out[0] = mxCreateNumericMatrix(height,width,mxUINT32_CLASS,mxREAL);
	label = (uint32_t*) mxGetData(out[0]);

	segment_image_merge(imdata, label, height,width,nchs,radius, k, min_size,num_regions);
}

