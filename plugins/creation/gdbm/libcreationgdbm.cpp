/******************************************************************************
*******************************************************************************
*******************************************************************************

    libferris
    Copyright (C) 2002 Ben Martin

    libferris is free software: you can redistribute it and/or modify
    it under the terms of the GNU General Public License as published by
    the Free Software Foundation, either version 3 of the License, or
    (at your option) any later version.

    libferris is distributed in the hope that it will be useful,
    but WITHOUT ANY WARRANTY; without even the implied warranty of
    MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
    GNU General Public License for more details.

    You should have received a copy of the GNU General Public License
    along with libferris.  If not, see <http://www.gnu.org/licenses/>.

    For more details see the COPYING file in the root directory of this
    distribution.

    $Id: libcreationgdbm.cpp,v 1.2 2010/09/24 21:31:52 ben Exp $

    *******************************************************************************
    *******************************************************************************
    ******************************************************************************/

#include <FerrisCreationPlugin.hh>

#ifdef FERRIS_HAVE_GDBM
#include <gdbm.h>
#endif

using namespace std;

namespace Ferris
{

    class CreationStatelessFunctorGDBM
        :
        public CreationStatelessFunctor
    {
    public:
        virtual fh_context create( fh_context c, fh_context md );
    };

    extern "C"
    {
        fh_CreationStatelessFunctor
        Create()
        {
            return new CreationStatelessFunctorGDBM();
        }
    };

    /********************************************************************************/
    /********************************************************************************/
    /********************************************************************************/
    
    fh_context
    CreationStatelessFunctorGDBM::create( fh_context c, fh_context md )
    {
#ifdef FERRIS_HAVE_GDBM
 
        fh_context newc = SubCreate_file( c, md );
        LG_FERRISCREATE_D << "Create gdbm at newc->getDirPath:" << newc->getURL() << endl;

        mode_t mode = getModeFromMetaData( md );
        mode_t oldumask = 0;
        bool ignoreUMask = toint(getStrSubCtx( md, "ignore-umask", "0" ));

        if( ignoreUMask ) oldumask = umask( 0 );
        GDBM_FILE db = gdbm_open( (char*)newc->getDirPath().c_str(), 0,
                                  GDBM_NOLOCK | GDBM_WRCREAT, mode, 0 );
        if( ignoreUMask ) umask( oldumask );

        if( !db )
        {
            fh_stringstream ss;
            ss << "SL_SubCreate_dir() error creating gdbm file"
               << " URL:" << newc->getURL()
               << " gdbm error:" <<  gdbm_strerror(gdbm_errno)
               << endl;
            Throw_FerrisCreateSubContextFailed( tostr(ss), GetImpl(c) );
        }

        gdbm_close( db );
        return newc;
#endif        

        fh_stringstream ss;
        ss << "SL_SubCreate() should not have gotten here, you have no "
           << "gdbm at compile time"
           << " url:" << c->getURL()
           << endl;
        Throw_FerrisCreateSubContextNotSupported( tostr(ss), GetImpl(c) );
    }
};
