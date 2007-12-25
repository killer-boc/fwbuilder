/* 

                          Firewall Builder

                 Copyright (C) 2000-2006 NetCitadel, LLC

  Author:  Vadim Kurland     vadim@vk.crocodile.org

  $Id$


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



#ifndef _FWOBJECT_CLIPBOARD_H
#define _FWOBJECT_CLIPBOARD_H

#include <vector>
#include <string>

class libfwbuilder::FWObject;

class FWObjectClipboard  {

    std::vector<std::string> ids;

public:

    FWObjectClipboard();
    ~FWObjectClipboard();

    /**
     *  adds an object to the clipboard
     */
    void add(libfwbuilder::FWObject*);

    /**
     * returns the last added object
     */
    libfwbuilder::FWObject* getObject();

    /**
     * clear the clipboard
     */
    void clear();

    std::vector<std::string>::iterator begin() { return ids.begin(); }
    std::vector<std::string>::iterator end() { return ids.end(); }
    std::vector<std::string>::reverse_iterator rbegin() { return ids.rbegin(); }
    std::vector<std::string>::reverse_iterator rend() { return ids.rend(); }
    int size() { return ids.size(); }
    
    static FWObjectClipboard  *obj_clipboard;
};


#endif

