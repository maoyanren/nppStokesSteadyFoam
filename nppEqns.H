    c1.storePrevIter();
    surfaceScalarField rhoFlux1
    (
	-z1*D1/kBT*eCharge*fvc::snGrad(phiV)*mesh.magSf()
    );
    c1.boundaryField().updateCoeffs();
    fvScalarMatrix c1Eqn
    (
        fvm::div(rhoFlux1, c1) + fvm::div(phi,c1) - fvm::laplacian(D1, c1)
    );        
    c1Eqn.relax();
    c1Res = c1Eqn.solve().initialResidual();

    c2.storePrevIter();
    surfaceScalarField rhoFlux2
    (
	-z2*D2/kBT*eCharge*fvc::snGrad(phiV)*mesh.magSf()
    );
    c2.boundaryField().updateCoeffs();
    fvScalarMatrix c2Eqn
    (
        fvm::div(rhoFlux2, c2) + fvm::div(phi,c2) - fvm::laplacian(D2, c2)
    );
    c2Eqn.relax();
    c2Res = c2Eqn.solve().initialResidual();

    phiV.storePrevIter();
    phiVRes = solve
    (
        fvm::laplacian(phiV) == -NA*eCharge*(z1*c1+z2*c2)/(epsilon0*epsilonr)
    ).initialResidual();
    phiV.relax();
    E = -fvc::grad(phiV);






















