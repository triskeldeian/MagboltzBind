# MagboltzBind
Programming language binds, examples and tests for Magboltz. Magboltz is a FORTRAN program, written by S. Biagi that solves the Boltzmann transport equations for electrons in gas mixtures under the influence of electric and magnetic fields.

This projects embeds this program in a modern build system with a C-based interface and other higher level bindings to allow it to be used in other projects

## Introducing Magboltz (from https://magboltz.web.cern.ch/)

Magboltz solves the Boltzmann transport equations for electrons in gas mixtures under the influence of electric and magnetic fields.

Calculates drift, diffusion, gain and attachment of electrons in gases with applied electric and magnetic fields at arbitrary angles. The common block structure of the results is outlined below.
Uses the RM48 random number generator internally.

The program allows anisotropic elastic and inelastic scattering, reference: NIM A 421 (1999) 234-240 The gas data base list below shows those x-sections which contain anisotropic scattering data.

PostScript plots of the database x-sections can be obtained on:- http://cern.ch/magboltz/cross.

This version allows spatial gradients to be included in the solution for the Townsend gain and attachment coeficients. The program automatically gives a solution with spatial gradients for both time of flight (TOF), pulsed townsend (PT) and steady state townsend (SST) parameters. The nomenclature is similar to Sakai et al. J. Phys. D10 (1977) 1035. The simulation of avalanche gain detectors at high field requires the use of SST Townsend parameters. The program automatically updates the common blocks /CTOWNS/ and /CTWNER/ with the SST parameters if the spatial gradients are greater than: | alpha - attachment | = 60/cm at NTP. where alpha is the Townsend coefficient and attachment the attachment coefficient. (For smaller values of | alpha - attachment | < 60/cm, the change of the gain or attachment is typically less than 3 % for the solution without spatial gradients).

Estimates of the Penning effect at high field can be obtained by inspection of the detailed collision frequencies for excited states in the gas mixtures. Penning effects can occur between excited states in the gas mixture which are higher in energy than the lowest ionisation potential in the mixture. Previous results in Argon hydrocarbon mixtures show a transfer efficiency of about 25 % from excited states in Argon to ionisation of hydrocarbons.

The program should always converge to a solution. the error on the integration should scale with the square root of the number of collisions (parameter NMAX). The output should always be checked to ensure that the number of collisions in the last energy bin is small, any value less than 500 should give reasonable systematic errors if the number of collisions is greater than 500 then the integration energy range should be increased.

The program is limited in precision by the statistical accuracy of the results. It is possible to obtain a statistical accuracy of better than 0.1 % on the drift velocity and 1 % on the diffusion coeficients in most counting gas mixtures in about 30 seconds of computing time on a PC, Alpha or workstation. At high field when the Townsend coeficient is included in the spatial gradient the computation time may be required to increase to a few minutes. When velocity vectors are small such as the case with small Lorentz angles the parameter NMAX will need to be increased to 20 or more.

## Building and installing

The project can be built using CMake 3.1 or later versions. The project doesn't currently have any other external dependencies.

By default the `CMAKE_BUILD_TYPE` is set to `RelWithDebInfo`, which enables all the release optimizations but includes the debug information as well in the final objects.

To choose the installation folder, the user should set the CMake variable `CMAKE_INSTALL_PREFIX` to the required destination. Within that folder the built objects will be installed according to the standard GNU folder structure (`bin` for binaries, `lib` for libraries and so on). The build will also install the appropriate CMake configuration files to allow dependant projects to include this one in their CMake builds. The CMake files are installed in the subfolder `share/MagboltzBind/cmake`.

For example, to build and install the project using Unix Makefiles, create a **build folder**, somewhere in the system, possibly not in the same folder as the repository itself (that is, make an out-of-source build). Let's label the root folder of the repository `<source_dir>` and the location where to install it `<install_dir>`, one can simply write

```bash
cmake -DCMAKE_INSTALL_PREFIX="<install_dir>" <source_dir> && make install
```

## Usage

The project creates an executable called MagboltzRun. This program requires an input file, formatted according to the scheme described in the [Magboltz website](https://magboltz.web.cern.ch/magboltz/usage.html). Some examples of those input files are collected in the `example` folder.

Each file is composed of an indefinite set of 4 lines, terminated by a single `0`. The format of each line is specified in the website above mentioned. Pay attention to the fact that each variable is allotted a fixed number of characters, independently to the actual value. For example, the content of the first line, encoded as 2I10, F10.5 means that the program is expected 2 integer, each of which in a 10 character wide field and a floating point number in a 10 character wide field with up to 5 decimal places. Note that both the `-` and `.` characters should be accounted in the field width.

To execute a single Magboltz Run, to calculate the properties of a specific mixture at a given electric and magnetic field, the user can use the following command line

```bash
MagboltzRun < input_file > output_file