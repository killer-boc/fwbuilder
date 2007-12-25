/* 

                          Firewall Builder

                 Copyright (C) 2006 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@vk.crocodile.org

  $Id: Preprocessor_pf.cpp 1034 2006-05-21 04:47:10Z vkurland $

  This program is free software which we release under the GNU General Public
  License. You may redistribute and/or modify this program under the terms
  of that license as published by the Free Software Foundation; either
  version 2 of the License, or (at your option) any later version.

  This program is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  To get a copy of the GNU General Public License, write to the Free Software
  Foundation, Inc., 59 Temple Place, Suite 330, Boston, MA  02111-1307  USA

*/


#include "Preprocessor_pf.h"

#include "fwbuilder/AddressTable.h"

using namespace libfwbuilder;
using namespace fwcompiler;
using namespace std;


void Preprocessor_pf::convertObject(FWObject *obj)
{
    Preprocessor::convertObject(obj);

    AddressTable *adt = AddressTable::cast(obj);
    if (adt!=NULL && adt->isCompileTime())
        adt->setRunTime(true);

}

