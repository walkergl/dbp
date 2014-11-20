/* deb_dep_check.c - Steven Arnow <s@rdw.se>,  2014 */
#define	LIBDPKG_VOLATILE_API

#ifndef DPKG_ARCH_NATIVE
#define	DPKG_ARCH_NATIVE arch_native
#endif

#include <stdlib.h>
#include <string.h>
#include <dpkg/dpkg.h>
#include <dpkg/arch.h>
#include <dpkg/dpkg-db.h>


void dbp_deb_dep_check_do_init() {
	push_error_context();
	dpkg_db_set_dir(NULL);
	modstatdb_open(msdbrw_readonly);
}


void dbp_deb_dep_check_do_free() {
	modstatdb_done();
	pop_error_context(ehflag_normaltidy);
}


int dbp_deb_dep_check_check_package(const char *pkgname) {
	struct pkgset *pkg;
	struct dpkg_arch *arch;
	
	pkg = pkg_db_find_set(pkgname);
	if (!pkg)
		return 0;
	
	for (; pkg; pkg = pkg->next) {
		if (strcmp(pkg->name, pkgname))
			continue;
		for (arch = (struct dpkg_arch *) pkg->pkg.installed.arch; arch; arch = (struct dpkg_arch *) arch->next) {
			if (arch->type == arch_native)
	/*			if (!strcmp(arch->name, arch_given))*/
					return 1;
		}
	}

	return 0;
}
