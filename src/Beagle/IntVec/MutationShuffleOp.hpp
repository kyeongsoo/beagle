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
 *  \file   Beagle/IntVec/MutationShuffleOp.hpp
 *  \brief  Definition of the class IntVec::MutationShuffleOp.
 *  \author Christian Gagne
 *  \author Marc Parizeau
 *  $Revision: 1.8 $
 *  $Date: 2007/08/08 19:26:34 $
 */

#ifndef Beagle_IntVec_MutationShuffleOp_hpp
#define Beagle_IntVec_MutationShuffleOp_hpp

#include "Beagle/IntVec.hpp"


namespace Beagle
{
namespace IntVec
{

/*!
 *  \class MutationShuffleOp Beagle/IntVec/MutationShuffleOp.hpp "Beagle/IntVec/MutationShuffleOp.hpp"
 *  \brief Indices permutation vector shuffle mutation operator class.
 *  \ingroup IntVecF
 */
class MutationShuffleOp : public EC::MutationOp
{

public:

	//! IntVec::MutationShuffleOp allocator type.
	typedef AllocatorT<MutationShuffleOp,EC::MutationOp::Alloc>
	Alloc;
	//! IntVec::MutationShuffleOp handle type.
	typedef PointerT<MutationShuffleOp,EC::MutationOp::Handle>
	Handle;
	//! IntVec::MutationShuffleOp bag type.
	typedef ContainerT<MutationShuffleOp,EC::MutationOp::Bag>
	Bag;

	explicit MutationShuffleOp(std::string inMutationPbName="intvec.mutshuf.indpb",
	                                 std::string inIntMutatePbName="intvec.mutshuf.intpb",
	                                 std::string inName="IntVec-MutationShuffleOp");
	virtual ~MutationShuffleOp()
	{ }

	virtual bool mutate(Beagle::Individual& ioIndividual, Context& ioContext);
	virtual void readWithSystem(PACC::XML::ConstIterator inIter, System& ioSystem);
	virtual void registerParams(System& ioSystem);
	virtual void writeContent(PACC::XML::Streamer& ioStreamer, bool inIndent=true) const;

protected:

	Double::Handle mIntMutateProba;   //!< Single integer mutation probability.
	std::string    mIntMutatePbName;  //!< Single integer mutation probability parameter name.

};

}
}

#endif // Beagle_IntVec_MutationShuffleOp_hpp
