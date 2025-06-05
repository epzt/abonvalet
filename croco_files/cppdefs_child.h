/* le contenu de ce fichier a été construit avec la documentation CROCO */
/* https://www.croco-ocean.org/documentation/ */

#define REGIONAL        /* REGIONAL Applications */
#if defined REGIONAL
                      /* Configuration Name */
# define ADCL_03
                      /* Parallelization */
# define OPENMP
                      /* Open Boundary Conditions */
# undef TIDES /* defini pour COTENTIN, non defini pour ADCL */
# define OBC_EAST
# define OBC_WEST
# define OBC_NORTH
# define  OBC_SOUTH
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
# define BULK_ECUMEV0
  /* end of model alternatives */
# define BULK_GUSTINESS /* Add in gustiness effect on the surface wind module. */
                      /* Surface Stress and Tracers */
# define SFLUX_CFB /* Activate current feedback on ... [Renault et al., 2020] */
# define CFB_STRESS /* ... surface stress */
# define CFB_WIND_TRA /* ... surface tracers */

# define FRC_BRY /* Activate processing of climatological data at OB points */
# define Z_FRC_BRY /* Activate open boundary forcing for sea level */
# define M2_FRC_BRY /* Activate open boundary forcing for barotropic velocities */
# define M3_FRC_BRY /* Activate open boundary forcing for baroclinic velocities */
# define T_FRC_BRY /* Activate open boundary forcing for tracers */
                      /* Vertical Mixing */
# define GLS_MIXING_3D /* Generic lengthscale parametrisation */
# define GLS_KOMEGA /* Activate K-OMEGA from Kolmogorov [1942] */
# define CANUTO_A /* Option for stability function */
                      /* Vertical Momentum Advection */
# define UV_VADV_WENO5  /* Activate 5th-order WENOZ vertical advection scheme */
                      /* Vertical Tracer Advection  */
# define  TS_VADV_WENO5 /* Activate 5th-order WENOZ vertical advection scheme */
                      /* Lateral Momentum Mixing */
# define UV_VIS2 /* Activate Laplacian horizontal mixing of momentum */
# define  UV_VIS_SMAGO /* Activate Smagorinsky param of turbulent viscosity */
# define UV_MIX_S /* Activate mixing on iso-sigma (constant sigma) surfaces */
# define VIS_COEF_3D
                      /* Lateral Tracer Mixing */
# define TS_DIF2 /* Activate Laplacian horizontal mixing of tracer */
# define TS_MIX_S /* Activate mixing along iso-sigma surfaces */
                      /* Lateral Momentum Advection */
# undef  DIF_COEF_3D
# define  UV_HADV_WENO5 /* Activate WENO 5th-order advection scheme */
                      /* Lateral Tracer Advection */
# define  TS_HADV_WENO5 /* Activate 5th-order WENOZ horizontal advection scheme */
                      /* Sponge layers for UV and TS */
# undef SPONGE /* defini pour COTENTIN, non defini pour ADCL */
                      /* Bottom Boundary Layer */
# define BBL /* Activate bottom boundary layer parametrization */
                      /* Wave-current interactions */
# define ANA_WWAVE /* Analytical values for waves */
# define ANA_BSEDIM /* Set analytical bed parameters (if SEDIMENT is undefined) */
                      /* Bottom Forcing */
# define ANA_BSFLUX /* Activate analytical bottom salinity flux (generally 0) */
# define ANA_BTFLUX /* Activate analytical bottom temperature flux */
                      /* Open Boundary Conditions */
# ifdef  TIDES
#  define SSH_TIDES /* process and use tidal sea level data */
#  define UV_TIDES /* process and use tidal current data */
#  define TIDERAMP /* Apply ramping on tidal forcing (1 day) at initialization */
#  define POT_TIDES
#  undef  TIDES_MAS
# endif
# define OBC_M2FLATHER /* Activate Flather OBC for barotropic velocities */
# define OBC_M2CHARACT /* Activate characteristic OBC for barotropic velocities */
# undef  OBC_M2ORLANSKI /* Activate radiative OBC for barotropic velocities */
# define OBC_M3ORLANSKI /* Activate Flather OBC for baroclinic velocities */
# define OBC_TORLANSKI /* Activate radiative OBC for tracers */
                        /* Input/Output */
/* Diagnostics */
# define AVERAGES /* Process and output time-averaged data */
# define AVERAGES_K /* Process and output time-averaged vertical mixing */
# define HOURLY_VELOCITIES /*  */
#endif /* END OF CONFIGURATION CHOICE */

#include "cppdefs_dev.h"
#include "set_global_definitions.h"