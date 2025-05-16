!======================================================================
! CROCO is a branch of ROMS developped at IRD, INRIA,
! Ifremer, CNRS and Univ. Toulouse III  in France
! The two other branches from UCLA (Shchepetkin et al)
! and Rutgers University (Arango et al) are under MIT/X style license.
! CROCO specific routines (nesting) are under CeCILL-C license.
!
! CROCO website : http://www.croco-ocean.org
!======================================================================
!

#define REGIONAL        /* REGIONAL Applications */

#if defined REGIONAL
/*
!====================================================================
!               REGIONAL (realistic) Configurations
!====================================================================
!
!----------------------
! BASIC OPTIONS
!----------------------
!
*/
                      /* Configuration Name */
# define ADCL_03
                      /* Parallelization */
# define OPENMP
# undef  MPI
                      /* OA and OW Coupling via OASIS (MPI) */
# undef  OA_COUPLING
# undef  OW_COUPLING /* Activate coupling with spectral wave model (WW3) */
# ifdef  OW_COUPLING
#  undef  OW_COUPLING_FULL
#  undef  WAVE_SMFLUX
# endif
                      /* Wave-current interactions */
# undef  MRL_WCI /* Set wave-current interaction model */
                      /* Open Boundary Conditions */
# undef TIDES /* Activate tidal forcing at open boundaries */
# define OBC_EAST
# define OBC_WEST
# define OBC_NORTH
# define  OBC_SOUTH
                      /* Calendar */
/* # define START_DATE dont exists in the doc */
# undef USE_CALENDAR
                      /* dedicated croco.log file */
# undef  LOGFILE
/*
!-------------------------------------------------
! PRE-SELECTED OPTIONS
!
! ADVANCED OPTIONS ARE IN CPPDEFS_DEV.H
!-------------------------------------------------
*/
                      /* Parallelization */
# undef  AUTOTILING
                      /* Grid configuration */
# define CURVGRID
# define SPHERICAL
# define MASKING
# define WET_DRY
# define NEW_S_COORD
                      /* Model dynamics */
# define SOLVE3D
# define UV_COR
# define UV_ADV
                      /* Equation of State */
# define SALINITY
# define TEMPERATURE
# define NONLIN_EOS
                      /* Surface Forcing */
# define BULK_FLUX
# ifdef  BULK_FLUX
   /* default : COARE3.0 */
#  define BULK_ECUMEV0
   /* end of model alternatives */
#  define BULK_GUSTINESS /* Add in gustiness effect on the surface wind module. Can be used for both bulk parametrizations. */
#  undef  BULK_LW /* Add in long-wave radiation feedback from model SST */
#  undef  SST_SKIN /* Activate skin sst computation [Zeng and Beljaars, 2005] */
#  undef  ANA_DIURNAL_SW /* Activate analytical diurnal modulation of short wave radiations (only appropriate if there is no diurnal cycle in data) */
#  undef  RAIN_FLUX /* Add E-P flux into the mass budget (added in omega) */
                      /* Atmospheric Pressure */
#  undef  READ_PATM /* Read atmospheric pressure instead of using default reference pressure and take into account the atmospherical pressure gradient in the equations */
#  ifdef  READ_PATM
#   define OBC_PATM /* In the case of READ_PATM, inverse barometer effect to the open boundaries if the atmospherical pressure is read in the meteo file */
#  endif
# endif
                      /* Surface Stress and Tracers */
# define SFLUX_CFB /* Activate current feedback on ... [Renault et al., 2020] */
# define CFB_STRESS /* ... surface stress (used by default when SFLUX_CFB is defined) */
# define CFB_WIND_TRA /* ... surface tracers (used by default when SFLUX_CFB is defined) */

# define FRC_BRY /* Activate processing of 1D/2D climatological or simulation/reanalysis data at open boundary points */
# ifdef  FRC_BRY
#  define Z_FRC_BRY /* Activate open boundary forcing for sea level */
#  define M2_FRC_BRY /* Activate open boundary forcing for barotropic velocities */
#  define M3_FRC_BRY /* Activate open boundary forcing for baroclinic velocities */
#  define T_FRC_BRY /* Activate open boundary forcing for tracers */
# endif

                      /* Vertical Mixing */
# undef  BODYFORCE /* Apply surface and bottom stresses as body-forces */
# define GLS_MIXING_3D /* Generic lengthscale parametrisation */
# ifdef  GLS_MIXING_3D
#  define GLS_KOMEGA /* Activate K-OMEGA (OMEGA=frequency of TKE dissipation) originating from Kolmogorov [1942] */
#  define CANUTO_A /* Option for stability function */
# endif

                      /* Vertical Momentum Advection */
/* Vertical Momentum Advection */
# define UV_VADV_WENO5  /* Activate 5th-order WENOZ quasi-monotone vertical advection scheme for UV */

/* Vertical Tracer Advection  */
# define  TS_VADV_WENO5 /* 5th-order WENOZ quasi-monotone advection scheme */

                      /* Lateral Explicit Momentum Mixing */
/* Lateral Momentum Mixing */
# define UV_VIS2 /* Activate Laplacian horizontal mixing of momentum */
# define  UV_VIS_SMAGO /* Activate Smagorinsky parametrization of turbulent viscosity (only with UV_VIS2) */
# define UV_MIX_S /* Activate mixing on iso-sigma (constant sigma) surfaces */
# define VIS_COEF_3D

/* Lateral Tracer Mixing */
# define TS_DIF2 /* Activate Laplacian horizontal mixing of tracer */
# define TS_MIX_S /* Activate mixing along iso-sigma surfaces */

                      /* Lateral Momentum Advection (default UP3) */
/* Lateral Momentum Advection */
# undef  DIF_COEF_3D
# define  UV_HADV_WENO5 /* Activate WENO 5th-order advection scheme */

                      /* Lateral Tracer Advection */
/* Lateral Tracer Advection */
# define  TS_HADV_WENO5 /* 5th-order WENOZ quasi-monotonic advection scheme for all tracers */

                      /* Sponge layers for UV and TS */
/* Sponge Layer */
# undef SPONGE /* Activate areas of enhanced viscosity and diffusivity near lateral open boundaries */
# undef  SPONGE_GRID /* Automatic setting of the sponge width and value */

                      /* Semi-implicit Vertical Tracer/Momentum Advection */
/* Adaptively implicit vertical advection */
# undef  VADV_ADAPT_IMP /* Activate adapative, Courant number dependent implicit advection scheme */

                      /* Bottom friction in fast 3D step */
/* Bottom Friction */
# undef  LIMIT_BSTRESS /* Bottom stress limitation forstability */
# undef  BSTRESS_FAST /* Bottom stress computed in step3d_fast */
/* Bottom Boundary Layer */
# define BBL /* Activate bottom boundary layer parametrization */

                      /* Wave-current interactions */
# ifdef  MRL_WCI /* Activate wave-current interactions */
#  define ANA_WWAVE /* Analytical values for waves */
#  define WAVE_STREAMING /* Set bottom wave streaming */
#  define WAVE_FRICTION /* Set bottom friction in WKB model (used for streaming) */
#  define WAVE_RAMP /* Set wave forcing ramp using wave_ramp parameter */
# else
#  define ANA_WWAVE /* Analytical values for waves */
#  define ANA_BSEDIM /* Set analytical bed parameters (if SEDIMENT is undefined) */
#  undef  Z0_BL /* Compute bedload roughness for ripple predictor and sediment purposes */
#  undef  Z0_BIO /* Determine (biogenic) bedform roughness ripple height and ripple length for silty beds */
#  undef  Z0_RIP /* Determine bedform roughness ripple height and ripple length for sandy beds */
# endif
                      /* Bottom Forcing */
# define ANA_BSFLUX /* Activate analytical bottom salinity flux (generally 0) */
# define ANA_BTFLUX /* Activate analytical bottom temperature flux (generally 0) */

                      /* Open Boundary Conditions */
# ifdef  TIDES
#  define SSH_TIDES /* process and use tidal sea level data */
#  define UV_TIDES /* process and use tidal current data */
#  define TIDERAMP /* Apply ramping on tidal forcing (1 day) at initialization
Warning! This should be undefined if restarting the model */
#  define POT_TIDES
#  undef  TIDES_MAS
# endif
# define OBC_M2FLATHER /* Activate Flather open boundary conditions for barotropic velocities */
# define OBC_M2CHARACT /* Activate open boundary conditions based on characteristic methods barotropic velocities */
# undef  OBC_M2ORLANSKI /* Activate radiative open boundary conditions for barotropic velocities */
# define OBC_M3ORLANSKI /* Activate Flather open boundary conditions for baroclinic velocities */
# define OBC_TORLANSKI /* Activate radiative open boundary conditions for tracers */

                        /* Input/Output */
/* Diagnostics */
# define AVERAGES /* Process and output time-averaged data */
# define AVERAGES_K /* Process and output time-averaged vertical mixing */
# undef  OUTPUTS_SURFACE /* 2d surface fields with higher sampling */
# define HOURLY_VELOCITIES /* DON'T SEEM TO REALLY EXIST */
                     /* Exact restart */
# undef  EXACT_RESTART /* DON'T SEEM TO REALLY EXIST */
                      /* Parallel reproducibility or restartabilty test */
# undef  RVTK_DEBUG
# undef  RVTK_DEBUG_PERFRST
# if defined RVTK_DEBUG && !defined RVTK_DEBUG_PERFRST
!    Parallel reproducibility test
#  define RVTK_DEBUG_ADVANCED
#  undef XXXRVTK_DEBUG_READ
# elif defined RVTK_DEBUG && defined RVTK_DEBUG_PERFRST
!    Restartability test
#  define EXACT_RESTART
#  undef  RVTK_DEBUG_ADVANCED
#  define XXXRVTK_DEBUG_READ
# endif
!    RVTK test (Restartability or Parallel reproducibility)
# if defined RVTK_DEBUG && defined BULK_FLUX && defined ONLINE
#  define BULK_MONTH_1DIGIT
# endif
/*
!                        Diagnostics
!--------------------------------------------
! 3D Tracer & momentum balance
! 2D Mixing layer balance
! Depth-mean vorticity and energy balance
! Eddy terms
!--------------------------------------------
!
*/
# undef  DO_NOT_OVERWRITE
# undef  RESTART_DIAGS

# undef  DIAGNOSTICS_TS
# undef  DIAGNOSTICS_UV
# ifdef  DIAGNOSTICS_TS
#  undef  DIAGNOSTICS_TS_ADV
#  undef  DIAGNOSTICS_TS_MLD
# endif

# undef  DIAGNOSTICS_TSVAR
# ifdef  DIAGNOSTICS_TSVAR
#  define DIAGNOSTICS_TS
#  define DIAGNOSTICS_TS_ADV
# endif

# undef  DIAGNOSTICS_VRT
# undef  DIAGNOSTICS_EK
# ifdef  DIAGNOSTICS_EK
#  undef  DIAGNOSTICS_EK_FULL
#  undef  DIAGNOSTICS_EK_MLD
# endif

# undef  DIAGNOSTICS_BARO
# undef  DIAGNOSTICS_PV
# undef  DIAGNOSTICS_DISS
# ifdef  DIAGNOSTICS_DISS
#  define DIAGNOSTICS_PV
# endif

# undef  DIAGNOSTICS_EDDY

# undef  TENDENCY
# ifdef  TENDENCY
#  define DIAGNOSTICS_UV
# endif
/*
!           Applications:
!---------------------------------
! Biology, floats, Stations,
! Passive tracer, Sediments, BBL
!---------------------------------
!
   Quasi-monotone lateral advection scheme (WENO5)
   for passive/biology/sediment tracers
*/
# if defined PASSIVE_TRACER || defined BIOLOGY || defined SEDIMENT \
                                               || defined MUSTANG
#  define BIO_HADV_WENO5
# endif
                      /*   Choice of Biology models   */
# ifdef  BIOLOGY
#  undef  PISCES
#  undef  BIO_NChlPZD
#  undef  BIO_N2ChlPZD2
#  define BIO_BioEBUS
                      /*   Biology options    */
#  ifdef  PISCES
#   undef  DIURNAL_INPUT_SRFLX
#   define key_pisces
#   define key_ligand
#   undef  key_pisces_quota
#   undef  key_pisces_npzd
#   undef  key_sediment
#  endif
#  ifdef  BIO_NChlPZD
#   define OXYGEN
#  endif
#  ifdef  BIO_BioEBUS
#   define NITROUS_OXIDE
#  endif
                      /*   Biology diagnostics    */
#  define DIAGNOSTICS_BIO
#  if defined DIAGNOSTICS_BIO && defined PISCES
#   define key_trc_diaadd
#  endif
# endif
                      /*   Lagrangian floats model    */
# ifdef FLOATS
#  undef  FLOATS_GLOBAL_ATTRIBUTES
#  undef  IBM
#  undef  RANDOM_WALK
#  ifdef  RANDOM_WALK
#   define DIEL_MIGRATION
#   define RANDOM_VERTICAL
#   define RANDOM_HORIZONTAL
#  endif
# endif
                      /*   Stations recording    */
# ifdef  STATIONS
#  define ALL_SIGMA
# endif
                      /*   USGS Sediment model     */
# ifdef  SEDIMENT
#  define SUSPLOAD
#  define BEDLOAD
#  define MORPHODYN
# endif
                      /*   MUSTANG Sediment model     */
# ifdef MUSTANG
#  undef  key_MUSTANG_V2
#  undef  key_MUSTANG_bedload
#  undef  MORPHODYN
#  define key_sand2D
#  define MUSTANG_CORFLUX
#  undef  key_tauskin_c_upwind
#  undef  WAVE_OFFLINE
# endif

#endif /* END OF CONFIGURATION CHOICE */

#include "cppdefs_dev.h"
#include "set_global_definitions.h"
