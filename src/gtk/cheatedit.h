// -*- C++ -*-
// VisualBoyAdvance - Nintendo Gameboy/GameboyAdvance (TM) emulator.
// Copyright (C) 2008 VBA-M development team

// This program is free software; you can redistribute it and/or modify
// it under the terms of the GNU General Public License as published by
// the Free Software Foundation; either version 2, or(at your option)
// any later version.
//
// This program is distributed in the hope that it will be useful,
// but WITHOUT ANY WARRANTY; without even the implied warranty of
// MERCHANTABILITY or FITNESS FOR A PARTICULAR PURPOSE.  See the
// GNU General Public License for more details.
//
// You should have received a copy of the GNU General Public License
// along with this program; if not, write to the Free Software Foundation,
// Inc., 59 Temple Place - Suite 330, Boston, MA 02111-1307, USA.

#ifndef __VBA_CHEATEDIT_H__
#define __VBA_CHEATEDIT_H__

#include <gtkmm.h>

#include "window.h"

namespace VBA
{

enum ECheatType
{
  CheatGeneric,
  CheatGSA,
  CheatCBA
};

class CheatEditDialog : public Gtk::Dialog
{
public:
  CheatEditDialog(GtkDialog* _pstDialog, const Glib::RefPtr<Gtk::Builder>& refBuilder);
  Glib::RefPtr<Gtk::TextBuffer> vGetCode();
  Glib::ustring vGetDesc();
  ECheatType vGetType();

private:
  void vOnApply();
  void vOnCancel();

  VBA::Window *                 m_poWindow;

  Gtk::Entry *                  m_poCheatDescEntry;
  Gtk::ComboBox *               m_poCheatTypeComboBox;
  Gtk::TextView *               m_poCheatInputTextView;
  Gtk::Button *                 m_poCheatApplyButton;
  Gtk::Button *                 m_poCheatCancelButton;
  Glib::RefPtr<Gtk::TextBuffer> m_poCheatInputBuffer;
  Glib::RefPtr<Gtk::ListStore>  m_poCheatTypeStore;
};

} // namespace VBA


#endif
