/*
 *  Open BEAGLE
 *  Copyright (C) 2001-2007 by Christian Gagne and Marc Parizeau
 *
 *  This library is free software; you can redistribute it and/or
 *  modify it under the terms of the GNU Lesser General Public
 *  License as published by the Free Software Foundation; either
 *  version 2.1 of the License, or (at your option) any later version.
 *
 *  This library is distributed in the hope that it will be useful,
 *  but WITHOUT ANY WARRANTY; without even the implied warranty of
 *  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
 *  Lesser General Public License for more details.
 *
 *  You should have received a copy of the GNU Lesser General Public
 *  License along with this library; if not, write to the Free Software
 *  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
 *
 *  Contact:
 *  Laboratoire de Vision et Systemes Numeriques
 *  Departement de genie electrique et de genie informatique
 *  Universite Laval, Quebec, Canada, G1K 7P4
 *  http://vision.gel.ulaval.ca
 *
 */

/*!
 *  \file   beagle/GA/MuWCommaLambdaCMAFltVecOp.hpp
 *  \brief  Definition of the class MuWCommaLambdaCMAFltVecOp.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.13 $
 *  $Date: 2007/08/17 18:09:10 $
 */


#ifndef Beagle_GA_MuWCommaLambdaCMAFltVecOp_hpp
#define Beagle_GA_MuWCommaLambdaCMAFltVecOp_hpp

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/Core/Pointer.hpp"
#include "Beagle/Core/PointerT.hpp"
#include "Beagle/Core/Allocator.hpp"
#include "Beagle/Core/AllocatorT.hpp"
#include "Beagle/Core/AbstractAllocT.hpp"
#include "Beagle/Core/Container.hpp"
#include "Beagle/Core/ContainerT.hpp"
#include "Beagle/Core/Operator.hpp"
#include "Beagle/Core/ReplacementStrategyOp.hpp"
#include "Beagle/Core/Float.hpp"
#include "Beagle/Core/Matrix.hpp"
#include "Beagle/Core/Vector.hpp"

namespace Beagle
{
namespace CMA
{

/*!
 *  \class MuWCommaLambdaCMAFltVecOp beagle/GA/MuWCommaLambdaCMAFltVecOp.hpp "beagle/GA/MuWCommaLambdaCMAFltVecOp.hpp"
 *  \brief CMA-ES (Mu_W+Lambda) replacement strategy operator class.
 *  \ingroup GAF
 *  \ingroup GAFV
 *
 *  CMA-ES (Mu_W,Lambda) replacement strategy class. Apply the CMA-ES algorithm (except mutation)
 *  on a population of GA float vectors. Use in conjunction of the CMA-ES mutation operator
 *  defined in class GA::MutationCMAFltVecOp.
 *
 *  Reference: Hansen, N. and Ostermeier, A. (2001). Completely Derandomized Self-Adaptation
 *  in Evolution Strategies. Evolutionary Computation, 9(2), pp. 159-195.
 *  See also: http://www.bionik.tu-berlin.de/user/niko/cmaes_inmatlab.html
 */
class MuWCommaLambdaCMAFltVecOp : public EC::MuCommaLambdaOp
{

public:

	//! MuWCommaLambdaCMAFltVecOp allocator type.
	typedef AllocatorT<MuWCommaLambdaCMAFltVecOp,EC::MuCommaLambdaOp::Alloc>
	Alloc;
	//! MuWCommaLambdaCMAFltVecOp handle type.
	typedef PointerT<MuWCommaLambdaCMAFltVecOp,EC::MuCommaLambdaOp::Handle>
	Handle;
	//! MuWCommaLambdaCMAFltVecOp bag type.
	typedef ContainerT<MuWCommaLambdaCMAFltVecOp,EC::MuCommaLambdaOp::Bag>
	Bag;

	explicit MuWCommaLambdaCMAFltVecOp(std::string inLMRatioName="ga.cmaes.mulambdaratio",
	                                   std::string inName="CMA-MuWCommaLambdaCMAFltVecOp");
	virtual ~MuWCommaLambdaCMAFltVecOp()
	{ }

	virtual void registerParams(System& ioSystem);
	virtual void operate(Deme& ioDeme, Context& ioContext);

protected:

	virtual void           generateChildren(Deme& ioDeme,
	                                        Context& ioContext,
	                                        unsigned int inNbChildren,
	                                        unsigned int inN,
	                                        CMAValues& ioCMAValues,
	                                        const Vector& inSelectionWeights) const;
	virtual double         generateSelectionWeights(unsigned int inPopSize,
	        Vector& outSelectionWeights) const;
	virtual CMAValues& getCMAValues(unsigned int inIndex,
	                                    unsigned int inN,
	                                    Context& ioContext) const;
	virtual void           updateValues(Deme& ioDeme,
	                                    Context& ioContext,
	                                    unsigned int inN,
	                                    double inMuEff,
	                                    const Vector& inSelectionWeights,
	                                    CMAValues& ioCMAValues) const;

	Double::Handle       mSigma;       //!< Initial CMA-ES sigma value.
	DoubleArray::Handle  mMaxValue;    //!< Maximum float vector values.
	DoubleArray::Handle  mMinValue;    //!< Minimum float vector values.

};

}
}

#endif // Beagle_GA_MuWCommaLambdaCMAFltVecOp_hpp


