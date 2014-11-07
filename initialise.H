    bool steadyState = false;
    bool converged = false;

    // difference between two steps
    scalar delta_c1 = fixNPP ? 0.0 : 1.0;
    scalar delta_c2 = fixNPP ? 0.0 : 1.0;
    scalar delta_phiV = fixNPP ? 0.0 : 1.0;
    scalar delta_U = fixU ? 0.0 : 1.0;
    scalar delta_p = fixU ? 0.0 : 1.0;

    // initialize residue variables
    scalar c1Res = fixNPP ? 0.0 : 1.0;
    scalar c2Res = fixNPP ? 0.0 : 1.0;
    scalar phiVRes = fixNPP ? 0.0 : 1.0;
    scalar uRes = fixU ? 0.0 : 1.0;
    scalar pRes = fixU ? 0.0 : 1.0;

    Info<< "\nReading convergence criteria\n" << nl
        << " c1 " << c1ResTol << nl 
        << " c2 " << c2ResTol << nl 
        << " phiV " << phiVResTol << nl
        << " U " << uResTol << nl
        << " p " << pResTol << nl << endl;
