/* -*-c++-*-
 
  This file is part of the IC reverse engineering tool degate.
 
  Copyright 2008, 2009 by Martin Schobert
 
  Degate is free software: you can redistribute it and/or modify
  it under the terms of the GNU General Public License as published by
  the Free Software Foundation, either version 3 of the License, or
  any later version.
 
  Degate is distributed in the hope that it will be useful,
  but WITHOUT ANY WARRANTY; without even the implied warranty of
  MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
  GNU General Public License for more details.
 
  You should have received a copy of the GNU General Public License
  along with degate. If not, see <http://www.gnu.org/licenses/>.
 
*/

#include <RecognitionManager.h>
#include <TemplateMatchingGUI.h>

using namespace degate;

RecognitionManager * RecognitionManager::instance = NULL;


RecognitionManager::RecognitionManager() {

  TemplateMatchingNormal_shptr tm_normal(new TemplateMatchingNormal());

  plugins.push_back(new TemplateMatchingGUI(tm_normal, "Template matching") );
}

RecognitionManager::~RecognitionManager() {
  for(plugin_list::iterator iter = plugins.begin();
      iter != plugins.end(); ++iter) {
    delete *iter;
  }
}

RecognitionManager * RecognitionManager::get_instance() {
  if(instance == NULL)
    instance = new RecognitionManager();
  return instance;
}

RecognitionManager::plugin_list RecognitionManager::get_plugins() {
  return plugins;
}