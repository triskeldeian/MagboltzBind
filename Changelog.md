## MagboltzBind changelog
These are only the changes of the MagboltzBind project

### VERSION 9.0.3
* Updated the library interface
* Built a simple test program 
* Changed the example input files according to the new input interface

### VERSION 8.9.1
* Added the CMake build system
* Added the single run executable based on the fortran sources
* Added the C header file for external binding
* Added a library to link magboltz to external codes

## Magboltz changelog
These are the changes introduced in the original Magboltz code

### VERSION 10.13
* O2 Upgrade improved fit to pure and argon mix data fit extended to 2000TD

### VERSION 10.12
* N2 Upgrade includes dissociative ionisation

### VERSION 10.11
* H2 upgrade includes dissociative ionisation allows calculation of total dissociation yield

### VERSION 10.10 
* CO2 upgrade with correct oscillator strength and dissociative ionisation 

### VERSION 10.9
* TMA (CH3)3-N upgrade

### VERSION 10.8
* CF4 upgrade neutral dissociation given by oscillator
* Oscillator strength to 33 dipole levels and 3 n0n dipole levels. ionisation now includes dissociative ionisation from rice university.

### VERSION 10.7
* CH4 2015 now includes all dissociative ionisation upgrade also in degrade

### VERSION 10.6
* Upgrade to SF6 also included in degrade

### VERSION 10.5
* Contains upgrade for isobutane (better townsend) both ch4 and c4h10 now have correct optical oscillator strength

### VERSION 10.4
* Corrected bef scaling in argon data base   argon2014

### VERSION 10.3
* Updated helium ionisation x-section   helium 2014

### VERSION 10.2
* Since version 6 the calculation of the statistical accuracy of the drift velocity and diffusion coeficients has underestimated the accuracy by a factor of approx. sqrt(10) . this error has been fixed in this version and now gives a factor of 10 shorter calculation time for the same accuracy.
* Increased decorreelation matrix to 2000000 collisions

### VERSION 10.1
* Includes better model of ionisation all noble gases include inner shells ionisations and auger emission model for outer shells. 
* Decorrelation for gases now dependent on mass saves 
* Computing time for gases not mixed with krypton or xenon

### VERSION 9.0.3
* Since version 6 the calculation of the statistical accuracy of the drift velocity and diffusion coefficients has underestimated the accuracy by a factor of approx. sqrt(10) . this error has been fixed in this version and now gives a factor of 10 shorter calculation time for the same accuracy. 
* Increased decorrelation matrix to 2000000 collisions

### VERSION 9.0.2 
* Update increases decorrelation matrix from 400000 collisions to 1000000. increases the calculation accuracy of the longitudinal diffusion in the most sensitive gas pure xenon to better than 2%.

### VERSION 9.0.1
* Update includes background gas motion(temperature) allows modelling of drift and diffusion at low fields
* Update to gas data subroutines to increase array size for inelastics to 250 levels and up to 8 ionisation levels per gas. 

### VERSION 8.9.7
* Update for krypton with 51 levels 

### VERSION 8.9.6
* Update for argon with small increase in excitation x-sections in resonance region for s-levels and compensating increase in elastic momentum transfer x-section at the maximum (11 ev) 

### VERSION 8.9.5
* New gas(44) trimethyl amine tma used as light emitter in wire chambers and dopant in penning dopant in xenon

### VERSION 8.9.4
* Updated xenon ionisation x-section (from ozkan sahin)

### VERSION 8.9.3 
* Updated xenon ionisation x-section

### VERSION 8.9.2
* Included hydrogen update with 106 levels

### VERSION 8.9.1
* Included c2h2f4 update

### VERSION 8.9 
* Included neon update with 45 levels

### VERSION 8.8 
* Included helium update with 49 levels
* Removed control on penning in pure gases which now allows calculation of hornbeck-molnar ionisation as a pseudo-penning effect

### VERSION 8.7
* Included xenon update with 50 levels

### VERSION 8.6 
* Included argon update with 44 levels

### VERSION 8.5 
* Correction for missing line in subroutine montea which caused errors in versions 8.4,8.3 and 8.2 when a magnetic field was included parallel to the e field

### VERSION 8.4 
* Included isobutane update

### VERSION 8.3 
* Included nitrogen update
 
 ### VERSION 8.2 
 * Introduced alternative formalism for angular distribution ref: phys.rev.65e 037402 okhrimovskyy et al.
 * Introduced control for angular distribution giving choice of two different anisotropic scat. formalisms.
* Increased decorrelation to  200000 collisions
* Included penning transfer efficiency
* Increased energy segementation from 2000 to 4000 steps

### VERSION 7.1
* Increased some array sizes and reduced diffusion array with shorter correlations (back to version 6.1) the longer correlation introduced problems with rounding errors on diffusion calculations on 32 bit pcs.
* Introduced sampling of most significant bits in collision array in order to reduce computation time for complex mixtures with many levels.

### VERSION 7.2
* Changed random number generator from drand48 to rm48.f all integers made integer*8
  
### VERSION 6.1 
* New co2 x-section set included version 6.2 updates of n2o and cd4 x-sections

### VERSION 6.3 
* Updates ch4 x-sections (only changes fano factors and has no effect on drift diffusion compared to 2002 data set)

### VERSION 6.4
* Increased diffusion array to allow longer decorrelation

### VERSION 6
* Removed all restrictions on angular scattering , all elastic and inelastic scattering processes can now have angular distributions ( if included in data base) if the elastic angular distribution exists then program uses this as an approximation to the angular distribution of the primary ionisation electron ( secondaries always have isotropic scattering). The angular distribution of the primary is taken to be the same as the angular distribution of an elastic scattered electron with the same final energy. This algorithm for the angular distribution of the primary ionisation electron reproduces experimental ionisation angular distributions and also gives the correct ranges for high energy electrons in gases. ranges are accurate up to 100KeV. N.B  If using water mixtures you will see an increase in computing time compared to previous versions since now 210 rotational
transitions are included in the data base.