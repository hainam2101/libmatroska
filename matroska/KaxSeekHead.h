/****************************************************************************
** libmatroska : parse Matroska files, see http://www.matroska.org/
**
** <file/class description>
**
** Copyright (C) 2002-2004 Steve Lhomme.  All rights reserved.
**
** This file is part of libmatroska.
**
** This library is free software; you can redistribute it and/or
** modify it under the terms of the GNU Lesser General Public
** License as published by the Free Software Foundation; either
** version 2.1 of the License, or (at your option) any later version.
** 
** This library is distributed in the hope that it will be useful,
** but WITHOUT ANY WARRANTY; without even the implied warranty of
** MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the GNU
** Lesser General Public License for more details.
** 
** You should have received a copy of the GNU Lesser General Public
** License along with this library; if not, write to the Free Software
** Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA
**
** See http://www.matroska.org/license/lgpl/ for LGPL licensing information.**
** Contact license@matroska.org if any conditions of this licensing are
** not clear to you.
**
**********************************************************************/

/*!
	\file
	\version \$Id: KaxSeekHead.h,v 1.7 2004/04/14 23:26:17 robux4 Exp $
	\author Steve Lhomme     <robux4 @ users.sf.net>
*/
#ifndef LIBMATROSKA_SEEK_HEAD_H
#define LIBMATROSKA_SEEK_HEAD_H

#include "matroska/KaxTypes.h"
#include "ebml/EbmlMaster.h"
#include "ebml/EbmlBinary.h"
#include "ebml/EbmlUInteger.h"

using namespace LIBEBML_NAMESPACE;

START_LIBMATROSKA_NAMESPACE

class KaxSegment;
class KaxSeek;

class MATROSKA_DLL_API KaxSeekHead : public EbmlMaster {
	public:
		KaxSeekHead();
		KaxSeekHead(const KaxSeekHead & ElementToClone) :EbmlMaster(ElementToClone) {}

		/*!
			\brief add an element to index in the Meta Seek data
			\note the element should already be written in the file
		*/
		void IndexThis(const EbmlElement & aElt, const KaxSegment & ParentSegment);

		KaxSeek * FindFirstOf(const EbmlCallbacks & Callbacks) const;
		KaxSeek * FindNextOf(const KaxSeek &aPrev) const;

        EBML_CONCRETE_CLASS(KaxSeekHead)
};

class MATROSKA_DLL_API KaxSeek : public EbmlMaster {
	public:
		KaxSeek();
		KaxSeek(const KaxSeek & ElementToClone) :EbmlMaster(ElementToClone) {}

		int64 Location() const;
		bool IsEbmlId(const EbmlId & aId) const;
		bool IsEbmlId(const KaxSeek & aPoint) const;

        EBML_CONCRETE_CLASS(KaxSeek)
};

class MATROSKA_DLL_API KaxSeekID : public EbmlBinary {
	public:
		KaxSeekID() {}
		KaxSeekID(const KaxSeekID & ElementToClone) :EbmlBinary(ElementToClone){}
		bool ValidateSize() const {return GetSize() <= 4;}

        EBML_CONCRETE_CLASS(KaxSeekID)
};

class MATROSKA_DLL_API KaxSeekPosition : public EbmlUInteger {
	public:
		KaxSeekPosition() {}
		KaxSeekPosition(const KaxSeekPosition & ElementToClone) :EbmlUInteger(ElementToClone) {}

        EBML_CONCRETE_CLASS(KaxSeekPosition)
};

END_LIBMATROSKA_NAMESPACE

#endif // LIBMATROSKA_SEEK_HEAD_H
