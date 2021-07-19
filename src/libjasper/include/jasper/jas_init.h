/*
 * Copyright (c) 2001-2002 Michael David Adams.
 * All rights reserved.
 */

/* __START_OF_JASPER_LICENSE__
 * 
 * JasPer License Version 2.0
 * 
 * Copyright (c) 2001-2006 Michael David Adams
 * Copyright (c) 1999-2000 Image Power, Inc.
 * Copyright (c) 1999-2000 The University of British Columbia
 * 
 * All rights reserved.
 * 
 * Permission is hereby granted, free of charge, to any person (the
 * "User") obtaining a copy of this software and associated documentation
 * files (the "Software"), to deal in the Software without restriction,
 * including without limitation the rights to use, copy, modify, merge,
 * publish, distribute, and/or sell copies of the Software, and to permit
 * persons to whom the Software is furnished to do so, subject to the
 * following conditions:
 * 
 * 1.  The above copyright notices and this permission notice (which
 * includes the disclaimer below) shall be included in all copies or
 * substantial portions of the Software.
 * 
 * 2.  The name of a copyright holder shall not be used to endorse or
 * promote products derived from the Software without specific prior
 * written permission.
 * 
 * THIS DISCLAIMER OF WARRANTY CONSTITUTES AN ESSENTIAL PART OF THIS
 * LICENSE.  NO USE OF THE SOFTWARE IS AUTHORIZED HEREUNDER EXCEPT UNDER
 * THIS DISCLAIMER.  THE SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS
 * "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR IMPLIED, INCLUDING
 * BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY, FITNESS FOR A
 * PARTICULAR PURPOSE AND NONINFRINGEMENT OF THIRD PARTY RIGHTS.  IN NO
 * EVENT SHALL THE COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, OR ANY SPECIAL
 * INDIRECT OR CONSEQUENTIAL DAMAGES, OR ANY DAMAGES WHATSOEVER RESULTING
 * FROM LOSS OF USE, DATA OR PROFITS, WHETHER IN AN ACTION OF CONTRACT,
 * NEGLIGENCE OR OTHER TORTIOUS ACTION, ARISING OUT OF OR IN CONNECTION
 * WITH THE USE OR PERFORMANCE OF THIS SOFTWARE.  NO ASSURANCES ARE
 * PROVIDED BY THE COPYRIGHT HOLDERS THAT THE SOFTWARE DOES NOT INFRINGE
 * THE PATENT OR OTHER INTELLECTUAL PROPERTY RIGHTS OF ANY OTHER ENTITY.
 * EACH COPYRIGHT HOLDER DISCLAIMS ANY LIABILITY TO THE USER FOR CLAIMS
 * BROUGHT BY ANY OTHER ENTITY BASED ON INFRINGEMENT OF INTELLECTUAL
 * PROPERTY RIGHTS OR OTHERWISE.  AS A CONDITION TO EXERCISING THE RIGHTS
 * GRANTED HEREUNDER, EACH USER HEREBY ASSUMES SOLE RESPONSIBILITY TO SECURE
 * ANY OTHER INTELLECTUAL PROPERTY RIGHTS NEEDED, IF ANY.  THE SOFTWARE
 * IS NOT FAULT-TOLERANT AND IS NOT INTENDED FOR USE IN MISSION-CRITICAL
 * SYSTEMS, SUCH AS THOSE USED IN THE OPERATION OF NUCLEAR FACILITIES,
 * AIRCRAFT NAVIGATION OR COMMUNICATION SYSTEMS, AIR TRAFFIC CONTROL
 * SYSTEMS, DIRECT LIFE SUPPORT MACHINES, OR WEAPONS SYSTEMS, IN WHICH
 * THE FAILURE OF THE SOFTWARE OR SYSTEM COULD LEAD DIRECTLY TO DEATH,
 * PERSONAL INJURY, OR SEVERE PHYSICAL OR ENVIRONMENTAL DAMAGE ("HIGH
 * RISK ACTIVITIES").  THE COPYRIGHT HOLDERS SPECIFICALLY DISCLAIM ANY
 * EXPRESS OR IMPLIED WARRANTY OF FITNESS FOR HIGH RISK ACTIVITIES.
 * 
 * __END_OF_JASPER_LICENSE__
 */

/*!
 * @file jas_init.h
 * @brief JasPer Initialization/Cleanup Code
 */

#ifndef JAS_INIT_H
#define JAS_INIT_H

/* The configuration header file should be included first. */
#include <jasper/jas_config.h>
#include <jasper/jas_malloc.h>
#include <jasper/jas_image.h>

#ifdef __cplusplus
extern "C" {
#endif

/*!
 * @addtogroup init
 * @{
 */

/*!
@brief
User-configurable settings for library.
*/
typedef struct {

	/*!
	The image format table to be used for initializing the library.
	*/
	jas_image_fmttab_t image_fmttab;

	/*!
	The allocator to be used by the library.
	*/
	jas_allocator_t allocator;
	
	/*! The maximum number of samples allowable in an image to be decoded. */
	size_t dec_default_max_samples;

	/*!
	The maximum amount of memory to be used by the library if the BMA
	allocator is used.
	*/
	size_t max_mem;

	/*!
	A flag indicating if atexit should be used to force jas_cleanup to
	be invoked upon exit.
	Enabling this flag is not recommended.
	*/
	bool atexit_cleanup;

	/*! Reserved for future use. */
	unsigned char reserved[256];

} jas_conf_t;

/*
NOTE: NOT NEEDED
JAS_DLLEXPORT void jas_get_conf(jas_conf_t* conf);
*/

/* This is for internal library use only. */
void jas_set_conf(const jas_conf_t* conf);

/* This is for internal library use only. */
jas_conf_t *jas_get_conf_ptr(void);

/******************************************************************************\
* Functions.
\******************************************************************************/

/*!
@brief Initialize the JasPer library.

@details
This function must be called before any other code in the JasPer library
is invoked.
This function registers the codecs that are enabled by default.

@returns
If successful, zero is returned; otherwise, a nonzero value is returned.
*/
JAS_DLLEXPORT
int jas_init(void);

/*!
@brief Initialize the JasPer library with custom values for various
configuration settings.

@param conf
A pointer to the data structure that specifies the configuration settings
to be used for the library.

@details
This function initializes the JasPer library, setting the values
of various configuration parameters for the library to those specified
by @c conf.
Any information needed by the library that is specified in the structure
pointed to by @c conf is copied before the function returns.

@returns
If successful, zero is returned; otherwise, a nonzero value is returned.
*/
JAS_DLLEXPORT
int jas_init_custom(const jas_conf_t *conf);

/*!
@brief Perform any clean up for the JasPer library.

@details
This function performs any clean up for the JasPer library.
*/
JAS_DLLEXPORT
void jas_cleanup(void);

/*!
@brief Get the default values for the configuration parameters (which
were established when the library was built).

@details
The configuration parameters are copied into the buffer supplied by the
caller.

@param conf
A pointer to a buffer to hold the configuration parameters.
*/
JAS_DLLEXPORT
void jas_get_default_conf(jas_conf_t *conf);

/*!
 * @}
 */

#ifdef __cplusplus
}
#endif

#endif
