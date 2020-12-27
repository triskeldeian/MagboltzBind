#ifndef MAGBOLTZ_MAGBOLTZ_H__
#define MAGBOLTZ_MAGBOLTZ_H__

#define MAGBOLTZ_VERSION_MAJOR 11
#define MAGBOLTZ_VERSION_MINOR 1
#define MAGBOLTZ_VERSION_PATCH 0

#define MAGBOLTZ_MAKE_VERSION(major, minor, patch) ((major)*10000 + (minor)*100 + (patch))
#define MAGBOLTZ_VERSION                                                                           \
    MAGBOLTZ_MAKE_VERSION(MAGBOLTZ_VERSION_MAJOR, MAGBOLTZ_VERSION_MINOR, MAGBOLTZ_VERSION_PATCH)

//
// Dynamic shared object (DSO) and dynamic-link library (DLL) support
//
#if defined(_WIN32) || defined(__WIN32__) || defined(WIN32) || defined(__CYGWIN__)
#define MAGBOLTZ_API __attribute__((__dllexport__))
#else
#define MAGBOLTZ_API __attribute__((__visibility__("default")))
#endif

#ifdef __cplusplus
namespace Magboltz
{
extern "C" {
#endif

/* Magboltz COMMON blocks
    Note that they are all global variables within the library*/

/* Magnetic field*/
extern struct
{
    const double eovb; /* E over B ratio. This is defined internally. Should not be assigned.*/
    const double wb;   /* The cyclotron frequency in radians per picosecond. Assigned internally */
    double btheta;     /* The angle between the magnetic and electric field in degrees */
    double bmag;       /* The magnitude of the magnetic field in kG*/
} bfld_;

/* Input parameter calculation */
extern struct
{
    long long nGas; /* Number of gases in the mixture*/
    long long nStep; /* Number of steps in the MC calculation */
    long long nAniso; /*The type of scattering cross section to use. Alowed values are 0, 1, 2*/
    double efinal;
    double estep;
    double akt;
    double ary;
    double tempc;
    double torr;
    long long ipen;
} inpt_;

extern struct
{
    double tmax;
    double small;
    double api;
    double estart;
    double theta;
    double phi;
    // double tcfmax[8];
    double rstart;
    double efield;
    long long nmax;
} setp_;

/* Physical constants */
extern struct
{
    double echarg;
    double emass;
    double amu;
    double pir2;
} cnsts_;

/* Definition of the gas mixture   */
extern struct
{
    long long ngasn[6];
} gasn_;

extern struct
{
    double an1, an2, an3, an4, an5, an6, an;
    double frac[6];
} ratio_;

/* Calculation results */
/* Drift velocity in cm/sec */
extern struct
{
    double wx, wy, wz;
} vel_;

extern struct
{
    double dwx, dwy, dwz;
} velerr_;

/* Diffusion */
extern struct
{
    double difxx, difyy, difzz;
    double difyz, difxy, difxz;
} diflab_;
extern struct
{
    double dxxer, dyyer, dzzer;
    double dyzer, dxyer, dxzer;
} diferb_;
extern struct
{
    double difln, diftr;
} difvel_;
extern struct
{
    double dfler, dfter;
} diferl_;

/* Townsend and attachment coefficient */
extern struct
{
    double alpha;
    double att;
} ctowns_;
extern struct
{
    double alper, atter;
} ctwner_;
extern struct
{
    double ralpha, ralper;
    double tofene, tofener, tofwv, tofwver;
    double tofdl, tofdler, tofdt, tofdter;
    double tofwr, tofwrer;
    double rattof, ratofer;
} tofout_;

extern struct
{
    double amgas[6];
    double vtmb[6];
    double tcfmx;
    double tcfmxg[6];
    int ithrm; /* Switch between static and thermal gas */
} thrm_;

/* Magboltz internal functions */

  void gasmix_(long long* ngs, double* q, 
        double* qin, long long* nin, double* e, double* ei, char* name, 
        double* virl, double* eb, double* peqel, double* peqin, 
        double* penfra, long long* kel, long long* kin, 
        double* qion, double* peqion, double* eion, long long* nion,
        char scrpt[260][50]);

/* Setup functions for static and thermal gas respectively */
void
setup_(int* );
void
setupt_(int* );

/* Setup the gas mixture cross sections for static and 
thermal gas respectively */
void
mixer_();
void
mixert_();

/* Calculations of the energy limit of the calculations
for the static and thermal gas respectively.
elimit and elimitt are for B and E aligned
elimitb and elimitbt are for B and E at 90 degrees
elimitc and elimitct are for other conditions*/
void
elimit_(long long* ielow);
void
elimitb_(long long* ielow);
void
elimitc_(long long* ielow);
void
elimitt_(long long* ielow);
void
elimitbt_(long long* ielow);
void
elimitct_(long long* ielow);

/* The actual MC calculations for static and 
thermal gas respectively
monte and montet are for the B=0 case
montea and monteat are for E and B aligned
monteb and montebt are for B at 90 degrees
montec and montect are for the other cases */
void
monte_();
void
montea_();
void
monteb_();
void
montec_();
void
montet_();
void
monteat_();
void
montebt_();
void
montect_();

/* Attachment calculations for static and 
thermal gas respectively
alpcalc and alpcalct are for B=0
alpclca and alpclcat are for E and B aligned
alpclcb and alpclcbt are for E and B at 90 degrees
alpclcc and alpclcct are for any other field configuration */
void
alpcalc_();
void
alpclca_();
void
alpclcb_();
void
alpclcc_();
void
alpcalct_();
void
alpclcat_();
void
alpclcbt_();
void
alpclcct_();

/* Output functions for static and thermal gase*/
void
prnter_();
void
output_();
void
output2_();
void
prntert_();
void
outputt_();
void
output2t_();

#ifdef __cplusplus
} // End extern C
} // End NS Magboltz
#endif

#endif