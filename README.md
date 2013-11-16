mod_doge
========

Apache module to provide data for dogescript applications via libdoge

What is it?
-----------

One key issue with dogescript today is providing high-quality doge data on the
backend (serverside) to the frontend dogescripts (clientside.) Previous, hacky
solutions involved generating this data on the fly via Perl or memory-heavy,
N-tier J2EE frameworks. Now, there's finally a better way.

**mod_doge** is a module for Apache which reproduces doge using modern, asexual
methods. Highly performant, thread safe, and unlikely to pee all over your carpet.

Requirements
============

mod_doge requires Apache 2.4 and a reasonable filesystem in which slashes slant the
right way. This is for perfectly legitimate, non-kludgy reasons. Wow. Also, I don't
know if it'll work properly in Centos because they put things in the wrong place there.

Usage
=====

Run `make`, and then `make install`. Your doge could probably do it, though you'd
probably have to type the command and then spread peanut butter on the "enter" key,
or something. Look, I'm just spitballing. How you compile your code is up to you.

Web API
=======

Obtaining doge data from a mod_doge enabled httpd is a simple REST away! 

##API URL
`http://hostname/much_doge`

##Authentication
Clients will authenticate to the API using their IP address and any cookies that may
have been distributed on the main fomain.

##Access Control
mod_doge uses the access control mechanisms built into Apache to provide comprehensive
security. For instance, you can probably ban people with your `virtualhost` if they're
all the time coming by and getting your doges all riled up. One time I had a neighbor
who had this bizarre fixation with my doge, and I'm not even kidding, he would always
whistle at the doges real loud until they were barking like crazy and then he'd leave.
Such trollage. Wow.

##Arguments and request options
You can optionally request doges. Or not. Don't argue about it.

##Bigger doges
`Ctrl` + `mousewheel`

##Smaller doges
`Ctrl` + `other mousewheel`

##Mouses suck

Use your `dogewheel` then.

##Extending the API
If you need doge data elsewhere, consider performing a 301 redirect to `/much_doge` using
`mod_rewrite`, either (again) in your `virtualhost` files or in `htaccess.`

Windows Support
===============

mod_doges does not support windows. They kept escaping, and that was really bad.
