#include "httpd.h"
#include "http_core.h"
#include "http_protocol.h"
#include "http_request.h"

#include "apr_strings.h"
#include "apr_network_io.h"
#include "apr_md5.h"
#include "apr_sha1.h"
#include "apr_hash.h"
#include "apr_base64.h"
#include "apr_dbd.h"
#include <apr_file_info.h>
#include <apr_file_io.h>
#include <apr_tables.h>
#include "util_script.h"
#include "libdoge.h"

static int doge_handler(request_rec *r) {
	char *fileloc;
	char *filename = apr_pcalloc(r->pool, 8190);
	char slash[] = "/";
	int lastslash;
	int i;
	fileloc = apr_pstrdup(r->pool, r->filename);
	
	for (i = 0; fileloc[i]; i++) { 
		if (fileloc[i] == slash[0]) {
			lastslash = i;
		}
	}
	if (lastslash == 0) return (DECLINED);
	
	for (i = ++lastslash; fileloc[i]; i++) {
		strncat(filename, &fileloc[i], 1);
	}
	
	if (strcmp(filename, "much_doge") == 0) {
		ap_set_content_type(r, "text/html");
		char doge[2048];
		doge_have(doge, false);
		ap_rprintf(r, "<meta http-equiv=\"Content-Type\" content=\"text/html; charset=utf-8\"/><pre>%s</pre>", doge);
		return (DONE);
	} else {
		ap_rprintf(r, "doge there (%s)", filename);
		return (DONE);
		//return (DECLINED);
	}
}

static void register_doges(apr_pool_t *pool) {
	ap_hook_handler(doge_handler, NULL, NULL, APR_HOOK_LAST);
}

module AP_MODULE_DECLARE_DATA	doge_module = 
{ 
    STANDARD20_MODULE_STUFF,
    NULL, /* Per-directory configuration handler */
    NULL,  /* Merge handler for per-directory configurations */
    NULL, /* Per-server configuration handler */
    NULL,  /* Merge handler for per-server configurations */
    NULL,      /* Any directives we may have for httpd */
    register_doges   /* Our hook registering function */
};
