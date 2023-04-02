//-------------------------------------------------------------------------------------------------------
// The MIT License (MIT)
//
// Copyright (c) 2021 Yoshiya Usui
//
// Permission is hereby granted, free of charge, to any person obtaining a copy
// of this software and associated documentation files (the "Software"), to deal
// in the Software without restriction, including without limitation the rights
// to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
// copies of the Software, and to permit persons to whom the Software is
// furnished to do so, subject to the following conditions:
//
// The above copyright notice and this permission notice shall be included in all
// copies or substantial portions of the Software.
//
// THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
// IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
// FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
// AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
// LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
// OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
// SOFTWARE.
//-------------------------------------------------------------------------------------------------------
#include "Forward2DQuadrilateralElementEdgeBased.h"
#include "CommonParameters.h"
#include "AnalysisControl.h"
#include "OutputFiles.h"
#include "ResistivityBlock.h"

// Constructer
Forward2DQuadrilateralElementEdgeBased::Forward2DQuadrilateralElementEdgeBased( const int planeID, const int iPol ):
	Forward2DQuadrilateralElement( planeID, iPol )
{}

// Destructer
Forward2DQuadrilateralElementEdgeBased::~Forward2DQuadrilateralElementEdgeBased(){
}

// Calculate Ex
std::complex<double> Forward2DQuadrilateralElementEdgeBased::calcEx( const int iElem, const double uCoord, const double vCoord, const MeshDataNonConformingHexaElement* const pMeshData ) const{

	if( m_planeID == MeshData::YZMinus || m_planeID == MeshData::YZPlus ){//YZ Plane		
		return std::complex<double>( 0.0, 0.0 ); 
	}else{//XZ Plane		
		return calcValueElectricFieldHorizontal( iElem, uCoord, vCoord, pMeshData );
	}

}

// Calculate Ey
std::complex<double> Forward2DQuadrilateralElementEdgeBased::calcEy( const int iElem, const double uCoord, const double vCoord, const MeshDataNonConformingHexaElement* const pMeshData ) const{

	if( m_planeID == MeshData::YZMinus || m_planeID == MeshData::YZPlus ){//YZ Plane
		return calcValueElectricFieldHorizontal( iElem, uCoord, vCoord, pMeshData );
	}else{//XZ Plane
		return std::complex<double>( 0.0, 0.0 ); 
	}

}

// Calculate Ez
std::complex<double> Forward2DQuadrilateralElementEdgeBased::calcEz( const int iElem, const double uCoord, const double vCoord, const MeshDataNonConformingHexaElement* const pMeshData ) const{

	return calcValueElectricFieldVertical( iElem, uCoord, vCoord, pMeshData );

}

// Calculate Hx
std::complex<double> Forward2DQuadrilateralElementEdgeBased::calcHx( const double freq, const int iElem, const double uCoord, const double vCoord, const MeshDataNonConformingHexaElement* const pMeshData ) const{

	if( m_planeID == MeshData::YZMinus || m_planeID == MeshData::YZPlus ){//YZ Plane
		return calcValueMagneticFieldPerpendicular( freq, iElem, uCoord, vCoord, pMeshData );
	}else{//XZ Plane
		return std::complex<double>( 0.0, 0.0 ); 
	}
}

// Calculate Hy
std::complex<double> Forward2DQuadrilateralElementEdgeBased::calcHy( const double freq, const int iElem, const double uCoord, const double vCoord, const MeshDataNonConformingHexaElement* const pMeshData ) const{

	if( m_planeID == MeshData::YZMinus || m_planeID == MeshData::YZPlus ){//YZ Plane
		return std::complex<double>( 0.0, 0.0 ); 
	}else{//XZ Plane
		return calcValueMagneticFieldPerpendicular( freq, iElem, uCoord, vCoord, pMeshData );
	}

}

// Calculate Hz
std::complex<double> Forward2DQuadrilateralElementEdgeBased::calcHz( const double freq, const int iElem, const double uCoord, const double vCoord, const MeshDataNonConformingHexaElement* const pMeshData ) const{

	return std::complex<double>( 0.0, 0.0 ); 

}