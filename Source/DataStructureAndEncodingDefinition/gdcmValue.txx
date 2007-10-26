/*=========================================================================

  Program: GDCM (Grass Root DICOM). A DICOM library
  Module:  $URL$

  Copyright (c) 2006-2007 Mathieu Malaterre
  Copyright (c) 1993-2005 CREATIS
  All rights reserved.
  See Copyright.txt or http://gdcm.sourceforge.net/Copyright.html for details.

     This software is distributed WITHOUT ANY WARRANTY; without even
     the implied warranty of MERCHANTABILITY or FITNESS FOR A PARTICULAR
     PURPOSE.  See the above copyright notice for more information.

=========================================================================*/
#include "gdcmValue.h"

#include "gdcmByteValue.h"
#include "gdcmSequenceOfItems.h"
#include "gdcmSequenceOfFragments.h"

namespace gdcm
{
  template <typename TSwap>
  IStream &Value::Read(IStream &is) {
    Value* v = this;
    if( ByteValue *bv = dynamic_cast<ByteValue*>(v) )
    {
	    bv->Read<TSwap>(is);
    }
    else if( SequenceOfItems *si = dynamic_cast<SequenceOfItems*>(v) )
    {
	    si->Read<TSwap>(is);
    }
    else if( SequenceOfFragments *sf = dynamic_cast<SequenceOfFragments*>(v) )
    {
	    sf->Read<TSwap>(is);
    }
    else
    {
	    assert( 0 && "error" );
    }
    return is;
  }

} // end namespace gdcm
