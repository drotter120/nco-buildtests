/* $Header: /data/zender/nco_20150216/nco/src/nco/nco_netcdf.h,v 1.20 2004-01-10 04:30:28 zender Exp $ */

/* Purpose: NCO wrappers for netCDF C library */

/* Copyright (C) 1995--2004 Charlie Zender
   This software may be modified and/or re-distributed under the terms of the GNU General Public License (GPL) Version 2
   See http://www.gnu.ai.mit.edu/copyleft/gpl.html for full license text */

/* Usage:
#include "nco_netcdf.h" *//* NCO wrappers for netCDF C library */

#ifndef NCO_NETCDF_H /* Contents have not yet been inserted in current source file */
#define NCO_NETCDF_H

/* Standard header files */
#include <stdio.h> /* stderr, FILE, NULL, printf */
#include <stdlib.h> /* strtod, strtol, malloc, getopt, exit */

/* 3rd party vendors */
#include <netcdf.h> /* netCDF definitions */

#ifdef __cplusplus
extern "C" {
#endif /* __cplusplus */

/* Definitions */
/* nco_fl_typ provides hooks for accessing non-netCDF files with nco_* routines */
enum nco_fl_typ{ /* [enm] File type */
  nco_fl_typ_nc, /* 0, netCDF file */
  nco_fl_typ_hd5 /* 1, HDF5 file */
}; /* end nco_fl_typ enum */

/* Begin Utility Routines */
const char * /* O [sng] Native C type */
c_typ_nm /* [fnc] Return string describing native C type */
(const nc_type type); /* O [enm] netCDF type */

const char * /* O [sng] Native Fortran77 type */
f77_typ_nm /* [fnc] Return string describing native Fortran77 type */
(const nc_type type); /* O [enm] netCDF type */

const char * /* O [sng] Native Fortran90 type */
f90_typ_nm /* [fnc] Return string describing native Fortran90 type */
(const nc_type type); /* O [enm] netCDF type */

void 
nco_dfl_case_nc_type_err /* [fnc] Print error and exit for illegal case */
(void);

void 
nco_err_exit /* [fnc] Print netCDF error message, routine name, then exit */
(const int rcd, /* I [enm] netCDF error code */ 
 const char * const msg); /* I [sng] Supplemental error message */

size_t /* O [B] Native type size */
nco_typ_lng /* [fnc] Convert netCDF type enum to native type size */
(const nc_type nco_typ); /* I [enm] netCDF type */

const char * /* O [sng] String describing type */
nco_typ_sng /* [fnc] Convert netCDF type enum to string */
(const nc_type type); /* I [enm] netCDF type */
/* End Utility Routines */

/* Begin file-level routines */
int nco_create(const char * const fl_nm,const int cmode,int * const nc_id);
int nco_open(const char * const fl_nm,const int mode,int * const nc_id);
int nco_redef(const int nc_id);
int nco_set_fill(const int nc_id,const int fill_mode,int * const old_mode);
int nco_enddef(const int nc_id);
int nco_sync(const int nc_id);
int nco_abort(const int nc_id);
int nco_close(const int nc_id);
int nco_inq(const int nc_id,int * const dmn_nbr_fl,int * const var_nbr_fl,int * const att_glb_nbr,int * const rec_dmn_id);
int nco_inq_ndims(const int nc_id,int * const dmn_nbr_fl);
int nco_inq_nvars(const int nc_id,int * const var_nbr_fl);
int nco_inq_natts(const int nc_id,int * const att_glb_nbr);
int nco_inq_unlimdim(const int nc_id,int * const rec_dmn_id);
/* End File routines */

/* Begin Dimension routines (_dim) */
int nco_def_dim(const int nc_id,const char * const dmn_nm,const long dmn_sz,int * const dmn_id);
int nco_inq_dimid(const int nc_id,const char * const dmn_nm,int * const dmn_id);
int nco_inq_dimid_flg(const int nc_id,const char * const dmn_nm,int * const dmn_id);
int nco_inq_dim(const int nc_id,const int dmn_id,char *dmn_nm,long *dmn_sz);
int nco_inq_dim_flg(const int nc_id,const int dmn_id,char *dmn_nm,long *dmn_sz);
int nco_inq_dimname(const int nc_id,const int dmn_id,char *dmn_nm);
int nco_inq_dimlen(const int nc_id,const int dmn_id,long *dmn_sz);
int nco_rename_dim(const int nc_id,const int dmn_id,const char * const dmn_nm);
/* End Dimension routines */

/* Begin Variable routines (_var) */
int nco_def_var(const int nc_id,const char * const var_nm,const nc_type var_typ,const int dmn_nbr,const int * const dmn_id,int * const var_id);
int nco_inq_var(const int nc_id,const int var_id,char * const var_nm,nc_type * const var_typ,int * const dmn_nbr,int * const dmn_id,int * const nbr_att);
int nco_inq_varid(const int nc_id,const char * const var_nm,int * const var_id);
int nco_inq_varid_flg(const int nc_id,const char * const var_nm,int * const var_id);
int nco_inq_varname(const int nc_id,const int var_id,char * const var_nm);
int nco_inq_vartype(const int nc_id,const int var_id,nc_type * const var_typ);
int nco_inq_varndims(const int nc_id,const int var_id,int * const dmn_nbr);
int nco_inq_vardimid(const int nc_id,const int var_id,int * const dmn_id);
int nco_inq_varnatts(const int nc_id,const int var_id,int * const nbr_att);
int nco_rename_var(const int nc_id,const int var_id,const char * const var_nm);
int nco_copy_var(const int nc_in_id,const int var_id,const int nc_out_id);

/* Start _get _put _var */
int nco_get_var1(const int nc_id,const int var_id,const long * const srt,void * const vp,const nc_type var_typ);
int nco_put_var1(const int nc_id,const int var_id,const long * const srt,const void * const vp,const nc_type type);
int nco_get_vara(const int nc_id,const int var_id,const long * const srt,const long * const cnt,void * const vp,const nc_type type);
int nco_put_vara(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const void * const vp,const nc_type type);
int nco_get_varm(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const long *srd,const long * const map,void * const vp,const nc_type type);
int nco_put_varm(const int nc_id,const int var_id,const long * const srt,const long * const cnt,const long *srd,const long * const map,const void * const vp,const nc_type type);
/* End Variable routines */

/* Begin Attribute routines (_att) */
int nco_inq_att(const int nc_id,const int var_id,const char * const att_nm,nc_type * const att_typ,long * const att_sz);
int nco_inq_att_flg(const int nc_id,const int var_id,const char * const att_nm,nc_type * const att_typ,long * const att_sz); 
int nco_inq_attid(const int nc_id,const int var_id,const char * const att_nm,int * const att_id); 
int nco_inq_attid_flg(const int nc_id,const int var_id,const char * const att_nm,int * const att_id); 
int nco_inq_atttype(const int nc_id,const int var_id,const char * const att_nm,nc_type * const att_typ); 
int nco_inq_attlen(const int nc_id,const int var_id,const char * const att_nm,long * const att_sz); 
int nco_inq_attname(const int nc_id,const int var_id,const int att_id,char * const att_nm); 
int nco_copy_att(const int nc_id_in,const int var_id_in,const char * const att_nm,const int nc_id_out,const int var_id_out);
int nco_rename_att(const int nc_id,const int var_id,const char * const att_nm,const char * const att_new_nm); 
int nco_del_att(const int nc_id,const int var_id,const char * const att_nm);
int nco_put_att(const int nc_id,const int var_id,const char * const att_nm,const nc_type att_typ,const long att_len,const void * const vp);
int nco_get_att(const int nc_id,const int var_id,const char * const att_nm,void * const vp,const nc_type att_typ);
/* End Attribute routines */

#ifdef __cplusplus
} /* end extern "C" */
#endif /* __cplusplus */

#endif /* NCO_NETCDF_H */
