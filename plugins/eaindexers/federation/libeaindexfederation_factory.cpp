/******************************************************************************
*******************************************************************************
*******************************************************************************

    libferris
    Copyright (C) 2004 Ben Martin

    This program is free software; you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation; either version 2 of the License, or
    (at your option) any later version.

    This program is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with this program; if not, write to the Free Software
    Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

    For more details see the COPYING file in the root directory of this
    distribution.

    $Id: libeaindexfederation_factory.cpp,v 1.2 2008/07/02 21:30:12 ben Exp $

*******************************************************************************
*******************************************************************************
******************************************************************************/

#include <Ferris/EAIndexerMetaInterface.hh>
#include <Ferris/FerrisCreationPlugin.hh>

#include <Ferris/EAIndexer.hh>
#include <Ferris/FactoriesCreationCommon_private.hh>

using namespace Ferris;
using namespace Ferris::EAIndex;

extern "C"
{
    FERRISEXP_API void SetupPlugin()
    {
        RegisterEAIndexPlugin(
            "libeaindexfederation.so",
            "eaindexfederation",
            "	<elementType name=\"eaindexfederation\">\n"
            "		<elementType name=\"primary-write-index-url\" "
            "           default=\"~/.ferris/ea-index/\">\n"
            "			<dataTypeRef name=\"string\"/>\n"
            "		</elementType>\n"
            "		<elementType name=\"read-only-federates\" >\n"
            "			<dataTypeRef name=\"StringListT\"/>\n"
            "           <default></default>\n"
            "		</elementType>\n"
            "	</elementType>\n"
            ,
            false
            ,
            ""
            );

    }
};
