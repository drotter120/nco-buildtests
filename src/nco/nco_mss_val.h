/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_mss_val.h,v 1.11 2004-01-10 04:30:28 zender Exp $ */

/* Purpose: Missing value utilities */

/* Copyright (C) 1995--2004 Charlie Zender
   This software may be modified and/or re-distributed under the terms of the GNU General Public License (GPL) Version 2
   See http://www.gnu.ai.mit.edu/copyleft/gpl.html for full license text */

/* Usage:
   #include "nco_mss_val.h" *//* Missing value utilities */

#ifndef NCO_MSS_VAL_H
#define NCO_MSS_VAL_H

#ifdef HAVE_CONFIG_H
#include <config.h> /* Autotools tokens */
#endif /* !HAVE_CONFIG_H */

/* Standard header files */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <string.h> /* strcmp. . . */

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions */
#include "nco_netcdf.h" /* NCO wrappers for netCDF C library */

/* Personal headers */
#include "nco.h" /* NCO definitions */
#include "nco_cnf_typ.h" /* Conform variable types */
#include "nco_mmr.h" /* Memory management */
#if (!defined HAVE_STRCASECMP) || (!defined HAVE_STRDUP)
#include "nco_sng_utl.h" /* String utilities */
#endif /* HAVE_STRCASECMP || HAVE_STRDUP */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

ptr_unn /* O [sct] Default missing value for type type */
nco_mss_val_mk /* [fnc] Return default missing value for type type */
(const nc_type type); /* I [enm] netCDF type of operand */

bool /* O [flg] One or both operands have missing value */
nco_mss_val_cnf /* [fnc] Change missing_value of var2 to missing_value of var1 */
(var_sct * const var1, /* I [sct] Variable with template missing value to copy */
 var_sct * const var2); /* I/O [sct] Variable with missing value to fill in/overwrite */

void
nco_mss_val_cp /* [fnc] Copy missing value from var1 to var2 */
(const var_sct * const var1, /* I [sct] Variable with template missing value to copy */
 var_sct * const var2); /* I/O [sct] Variable with missing value to fill in/overwrite */

int /* O [flg] Variable has missing value on output */
nco_mss_val_get /* [fnc] Update number of attributes, missing_value of variable */
(const int nc_id, /* I [id] netCDF input-file ID */
 var_sct * const var); /* I/O [sct] Variable with missing_value to update */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_MSS_VAL_H */
