#include "Magboltz/magboltz.h"
#include <cmath>

#include <iostream>

constexpr double mathpi = M_PI;
constexpr double halfpi = M_PI_2;

int
main()
{
    for (auto i = 0U; i < 6; ++i)
    {
        Magboltz::gasn_.ngasn[i] = 0;
        Magboltz::ratio_.frac[0] = 0.0;
    }
    // Set input parameters in Magboltz common blocks.
    // First card
    Magboltz::inpt_.nGas = 1;
    Magboltz::setp_.nmax = 10;
    Magboltz::inpt_.ipen = 0;
    Magboltz::thrm_.ithrm = 1;
    Magboltz::inpt_.efinal = 0.0;

    // Second card: gases
    Magboltz::gasn_.ngasn[0] = 2;

    // // Third card: fraction
    Magboltz::ratio_.frac[0] = 100.0;
    Magboltz::inpt_.tempc = 25.0;
    Magboltz::inpt_.torr = 750.0;

    // Fourth card: fields
    Magboltz::setp_.efield = 1000.0;
    Magboltz::bfld_.bmag = 0.0;
    Magboltz::bfld_.btheta = 0.0;

    Magboltz::inpt_.nStep = 4000;
    Magboltz::inpt_.nAniso = 2;

    const double TempK = Magboltz::inpt_.tempc + 273.15;
    // Call Magboltz internal setup routine.
    int last = 0;
    Magboltz::setupt_(&last);
    if (last > 0)
    {
        return last;
    }

    if (Magboltz::inpt_.efinal == 0.0)
    {
        if (Magboltz::setp_.efield * (TempK) / (Magboltz::inpt_.torr * 293.15) > 15.0)
        {
            Magboltz::inpt_.efinal = 8.;
        }
        else
        {
            Magboltz::inpt_.efinal = 0.5;
        }
        Magboltz::setp_.estart = Magboltz::inpt_.efinal / 50.0;
    }

    long long ielow = 1;
    while (ielow == 1)
    {
        Magboltz::mixert_();
        if (Magboltz::bfld_.bmag == 0. || Magboltz::bfld_.btheta == 0. ||
            std::fabs(Magboltz::bfld_.btheta) == 180.0)
        {
            Magboltz::elimitt_(&ielow);
        }
        else if (Magboltz::bfld_.btheta == 90.0)
        {
            Magboltz::elimitbt_(&ielow);
        }
        else
        {
            Magboltz::elimitct_(&ielow);
        }
        if (ielow == 1)
        {
            // Increase the max. energy.
            Magboltz::inpt_.efinal *= std::sqrt(2.);
            Magboltz::setp_.estart = Magboltz::inpt_.efinal / 50.;
        }
    }

    Magboltz::prntert_();

    // Run the Monte Carlo calculation.
    if (Magboltz::bfld_.bmag == 0.)
    {
        Magboltz::montet_();
    }
    else if (Magboltz::bfld_.btheta == 0. || Magboltz::bfld_.btheta == 180.0)
    {
        Magboltz::monteat_();
    }
    else if (Magboltz::bfld_.btheta == 90.0)
    {
        Magboltz::montebt_();
    }
    else
    {
        Magboltz::montect_();
    }
    Magboltz::outputt_();

    // If attachment or ionisation rate is greater than sstmin,
    // include spatial gradients in the solution.
    const double sstmin = 30.;
    const double epscale = 760. * (TempK) / (Magboltz::inpt_.torr * 293.15);
    double alpp = Magboltz::ctowns_.alpha * epscale;
    double attp = Magboltz::ctowns_.att * epscale;

    if (fabs(alpp - attp) > sstmin || alpp > sstmin || attp > sstmin)
    {
        if (Magboltz::bfld_.bmag == 0.)
        {
            Magboltz::alpcalct_();
        }
        else if (Magboltz::bfld_.btheta == 0. || Magboltz::bfld_.btheta == 180.0)
        {
            Magboltz::alpclcat_();
        }
        else if (Magboltz::bfld_.btheta == 90)
        {
            Magboltz::alpclcbt_();
        }
        else
        {
            Magboltz::alpclcct_();
        }
    }
    Magboltz::output2t_();
}