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
 *  \file   Beagle/ParetoFrontCalculateOp.hpp
 *  \brief  Definition of the class ParetoFrontCalculateOp.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.10 $
 *  $Date: 2007/08/08 19:26:45 $
 */

#ifndef Beagle_EMO_ParetoFrontCalculateOp_hpp
#define Beagle_EMO_ParetoFrontCalculateOp_hpp

#include "Beagle/config.hpp"
#include "Beagle/macros.hpp"
#include "Beagle/Core/Object.hpp"
#include "Beagle/Core/AllocatorT.hpp"
#include "Beagle/Core/PointerT.hpp"
#include "Beagle/Core/ContainerT.hpp"
#include "Beagle/Core/WrapperT.hpp"
#include "Beagle/Core/Operator.hpp"
#include "Beagle/Core/UInt.hpp"
#include "Beagle/Core/String.hpp"
#include "Beagle/Core/Bool.hpp"
#include "Beagle/Core/UInt.hpp"
#include "Beagle/Core/Vivarium.hpp"
#include "Beagle/Core/Context.hpp"

namespace Beagle
{
namespace EMO
{

/*!
 *  \class ParetoFrontCalculateOp Beagle/ParetoFrontCalculateOp.hpp "Beagle/ParetoFrontCalculateOp.hpp"
 *  \brief Evaluate Pareto front operator class.
 *  \ingroup ECF
 *  \ingroup Op
 *
 *  Evaluate Pareto front from demes and vivarium and put it in place of the actual hall-of-fame.
 *  The Pareto front is evaluated just before milestones are written. If previous hall-of-fame are
 *  presents in the demes/vivarium, they are erased. This operator must be in the evolver's operator
 *  sets between the termination criterion check operators and the MilestoneWriteOp operator.
 */
class ParetoFrontCalculateOp : public Operator
{

public:

	//! ParetoFrontCalculateOp allocator type
	typedef AllocatorT<ParetoFrontCalculateOp,Operator::Alloc>
	Alloc;
	//! ParetoFrontCalculateOp handle type.
	typedef PointerT<ParetoFrontCalculateOp,Operator::Handle>
	Handle;
	//! ParetoFrontCalculateOp bag type.
	typedef ContainerT<ParetoFrontCalculateOp,Operator::Bag>
	Bag;

	explicit ParetoFrontCalculateOp(std::string inName="ParetoFrontCalculateOp");
	virtual ~ParetoFrontCalculateOp()
	{ }

	virtual void registerParams(System& ioSystem);
	virtual void operate(Deme& ioDeme, Context& ioContext);

private:
	String::Handle    mMilestonePrefix;     //!< Prefix of the milestone filenames.
	UInt::Handle      mWritingInterval;     //!< Milestone's writing interval (in generation).
	Bool::Handle      mPerDemeMilestone;    //!< True: write a milestone for every deme.
	UIntArray::Handle mPopSize;             //!< Population size for the evolution.

};

}
}

#endif // Beagle_ParetoFrontCalculateOp_hpp
