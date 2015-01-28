/******************************************************************************
*******************************************************************************
*******************************************************************************

    ferris echo

    Copyright (C) 2001 Ben Martin

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

    $Id: sqlsimplequery.cpp,v 1.3 2008/05/25 21:30:06 ben Exp $

*******************************************************************************
*******************************************************************************
******************************************************************************/

#include <string>
#include <list>
#include <set>
#include <vector>
#include <algorithm>
#include <iomanip>
#include <unistd.h>

#include <Ferris.hh>
#include <ContextPopt.hh>

using namespace std;
using namespace Ferris;

const string PROGRAM_NAME = "sqlsimplequery";

void usage(poptContext optCon, int exitcode, char *error, char *addl)
{
    
    poptPrintUsage(optCon, stderr, 0);
    if (error) fprintf(stderr, "%s: %s0", error, addl);
    exit(exitcode);
}



void printstate( const fh_iostream& ss )
{
    if( !ss.good() )
    {
        cerr << " rdstate:" << ss.rdstate() << endl;
        cerr << " good state:" << ss.good() << endl;
        cerr << " eof  state:" << ss.eof() << endl;
        cerr << " fail state:" << ss.fail() << endl;
        cerr << " bad  state:" << ss.bad() << endl;
    }
}


///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////
///////////////////////////////////////////////////////////////////////////////


int main( int argc, const char** argv )
{
    /* Parse --logging options, this should be done early */
    ParseOnly_FERRIS_POPT_OPTIONS( PROGRAM_NAME, argc, argv );

    poptContext optCon;
    try
    {
        fh_context c = Resolve( "mysql:///localhost/mysql_cpp_data" );
        fh_context md = Resolve( "./sqlsimplequery.xml/sdatequery" );

        cerr << "Query:" << getStrAttr( md, "sql-query", "" ) << endl;
        
        struct poptOption optionsTable[] = {
            FERRIS_POPT_OPTIONS
            FERRIS_CONTEXTPOPT_OPTIONS( md )            
            POPT_AUTOHELP
            POPT_TABLEEND
        };

        optCon = poptGetContext(PROGRAM_NAME.c_str(), argc, argv, optionsTable, 0);
        poptSetOtherOptionHelp(optCon, "[OPTIONS]* ...");
    
        
        /***/
        int ch=-1;
        while ((ch = poptGetNextOpt(optCon)) >= 0)
        {}
        cout << "Option processing done." << endl;

        /*
         * Make connection and dump query results
         */
        fh_context sqlc = c->createSubContext("dummy", md );
        fh_iostream ss  = sqlc->getIOStream();

        copy( istreambuf_iterator<char>(ss),
              istreambuf_iterator<char>(),
              ostreambuf_iterator<char>(cout));
        cout << endl;
    }
    catch( exception& e )
    {
        cerr << "Cought exception:" << e.what() << endl << flush;
    }
    
    poptFreeContext(optCon);
    return 0;
}
