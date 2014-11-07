    surfaceScalarField phi_temp
    (
	"phi_temp",
	fvc::interpolate(U) & mesh.Sf()
    );
    surfaceScalarField c1Flux
    (
	"c1Flux",
	-D1*fvc::snGrad(c1)
	-z1*D1/kBT*eCharge*fvc::snGrad(phiV)*fvc::interpolate(c1)
	+phi_temp/mesh.magSf()*fvc::interpolate(c1)
    );

    surfaceScalarField c2Flux
    (
	"c2Flux",
	-D2*fvc::snGrad(c2)
	-z2*D2/kBT*eCharge*fvc::snGrad(phiV)*fvc::interpolate(c2)
	+phi_temp/mesh.magSf()*fvc::interpolate(c2)
    );

    surfaceScalarField cFlux = NA*eCharge*(z1*c1Flux+z2*c2Flux);

    surfaceScalarField::GeometricBoundaryField& IFlux = cFlux.boundaryField();

    Info<< "\nCalculating total current\n" << endl;
    forAll(mesh.boundary(), patchi)
    {
        Info<< mesh.boundary()[patchi].name()
            << " "
            << gSum
               (
                   mesh.magSf().boundaryField()[patchi]
                   *IFlux[patchi]
               )
            << endl;
    }
    Info<< endl;
    
    /*
    //phi = fvc::interpolate(U) & mesh.Sf();
    surfaceScalarField::GeometricBoundaryField& qFlux = phi_temp.boundaryField();

    Info<< "\nCalculating total flow rate\n" << endl;
    forAll(mesh.boundary(), patchi)
    {
	Info<< mesh.boundary()[patchi].name()
	<< " "
	<< gSum
	   (
	       qFlux[patchi]
	   )
	<< endl;
    }
    Info<< endl;
    */
