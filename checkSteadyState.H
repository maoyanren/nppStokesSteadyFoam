// compare solution with the previous iteration

if(!fixU)
{
    delta_U = max(mag(U-U.prevIter())).value() / (max(mag(U)).value() + VSMALL);
    delta_p = max(mag(p-p.prevIter())).value() / (max(mag(p)).value() + VSMALL);
}
if(!fixNPP)
{
    delta_c1 = max(mag(c1-c1.prevIter())).value() / (max(mag(c1)).value() + VSMALL);
    delta_c2 = max(mag(c2-c2.prevIter())).value() / (max(mag(c2)).value() + VSMALL);
    delta_phiV = max(mag(phiV-phiV.prevIter())).value() / (max(mag(phiV)).value() + VSMALL);
}

Info<< ">> delta_U = " << delta_U << nl 
    << ">> delta_p = " << delta_p << nl 
    << ">> delta_c1 = " << delta_c1 << nl
    << ">> delta_c2 = " << delta_c2 << nl
    << ">> delta_phiV = " << delta_phiV << nl << endl; 

steadyState = (delta_c1 < delta_c1_max) 
	    && (delta_c2 < delta_c2_max)
 	    && (delta_phiV < delta_phiV_max)
	    && (delta_U < delta_U_max)
	    && (delta_p < delta_p_max);

converged = (c1Res < c1ResTol)
	  && (c2Res < c2ResTol)
	  && (phiVRes < phiVResTol)
	  && (uRes < uResTol)
	  && (pRes < pResTol);

if(steadyState)
{
    Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
	<< nl << "The solution has reached steady state."
        << nl << endl;

    runTime.writeNow();

    break;
}

if(converged)
{
    Info<< "ExecutionTime = " << runTime.elapsedCpuTime() << " s"
        << "  ClockTime = " << runTime.elapsedClockTime() << " s"
	<< nl << "The solution has converged."
        << nl << endl;

    runTime.writeNow();

    break;
}
