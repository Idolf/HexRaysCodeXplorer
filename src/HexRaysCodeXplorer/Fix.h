/// This file fix some missing function in 1.6 version support for ida 6.6 sdk

#ifndef _FIX_HPP
#define _FIX_HPP
#include <ida.hpp>
#include <idp.hpp>
#include <bytes.hpp>
#include <xref.hpp>
#include <name.hpp>
#include <funcs.hpp>
#include <segment.hpp>
#include <struct.hpp>
#include <loader.hpp>
#include <search.hpp>

#include <string.h>
#include <stdarg.h>
#include <tchar.h>


inline void f_get_ea_name(qstring* name, ea_t addr) {
	char buff[MAXSTR];
	get_name(BADADDR, addr, buff, (MAXSTR - 1));
	*name = qstring(buff);
}

inline qstring f_get_short_name(ea_t addr) {
	char buff[MAXSTR];
	get_short_name(BADADDR, addr, buff, (MAXSTR - 1));
	return qstring(buff);
}

inline char *f_get_func_name2(qstring* name, ea_t addr) {
	char buff[MAXSTR];
	char *rv = 0;
	rv = get_func_name(addr, buff, (MAXSTR - 1));
	*name = qstring(buff);

	return rv;
}

inline qstring f_get_struc_name(tid_t struct_tyle_id) {
	char buff[MAXSTR];
	get_struc_name(struct_tyle_id, buff, (MAXSTR - 1));
	return qstring(buff);
}

inline qstring f_get_member_name2(tid_t struct_tyle_id) {
	char buff[MAXSTR];
	get_member_name(struct_tyle_id, buff, (MAXSTR - 1));
	return qstring(buff);
}

inline void f_set_custom_viewer_handlers(
        TCustomControl *custom_viewer,
        custom_viewer_keydown_t *keyboard_handler,
        custom_viewer_popup_t *popup_handler,
		void *sheker,
        custom_viewer_dblclick_t *dblclick_handler,
        custom_viewer_curpos_t *curpos_handler,
        custom_viewer_close_t *close_handler,
        void *user_data) {
	set_custom_viewer_handlers(custom_viewer,
		keyboard_handler,
		popup_handler,
		dblclick_handler,
		curpos_handler,
		close_handler,
		user_data
		);
}
#endif