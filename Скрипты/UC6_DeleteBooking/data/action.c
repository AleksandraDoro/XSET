Action()
{

	web_set_sockets_option("SSL_VERSION", "AUTO");

	web_add_auto_header("Sec-Fetch-Dest", 
		"frame");

	web_add_auto_header("Sec-Fetch-Mode", 
		"navigate");

	web_add_auto_header("Sec-Fetch-Site", 
		"same-origin");

	web_add_auto_header("Upgrade-Insecure-Requests", 
		"1");

	web_add_auto_header("sec-ch-ua", 
		"\"Not_A Brand\";v=\"99\", \"Google Chrome\";v=\"109\", \"Chromium\";v=\"109\"");

	web_add_auto_header("sec-ch-ua-mobile", 
		"?0");

	web_add_auto_header("sec-ch-ua-platform", 
		"\"Windows\"");

	web_url("welcome.pl", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=true", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/", 
		"Snapshot=t1.inf", 
		"Mode=HTML", 
		LAST);

	lr_start_transaction("signUpButton");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(104);

	web_url("login.pl", 
		"URL=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/WebTours/home.html", 
		"Snapshot=t2.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signUpButton",LR_AUTO);

	lr_start_transaction("fillProfile");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(129);

	web_submit_data("login.pl_2", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl?username=&password=&getInfo=true", 
		"Snapshot=t3.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=passwordConfirm", "Value=bean", ENDITEM, 
		"Name=firstName", "Value=Jojo", ENDITEM, 
		"Name=lastName", "Value=Bean", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=54", ENDITEM, 
		"Name=register.y", "Value=9", ENDITEM, 
		LAST);

	lr_end_transaction("fillProfile",LR_AUTO);

	lr_think_time(108);

	lr_start_transaction("profileFill");

	web_submit_data("login.pl_3", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t4.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=username", "Value=mam", ENDITEM, 
		"Name=password", "Value=lady", ENDITEM, 
		"Name=passwordConfirm", "Value=lady", ENDITEM, 
		"Name=firstName", "Value=Mam", ENDITEM, 
		"Name=lastName", "Value=Lady", ENDITEM, 
		"Name=address1", "Value=", ENDITEM, 
		"Name=address2", "Value=", ENDITEM, 
		"Name=register.x", "Value=83", ENDITEM, 
		"Name=register.y", "Value=7", ENDITEM, 
		LAST);

	lr_end_transaction("profileFill",LR_AUTO);

	lr_start_transaction("afterReg");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(23);

	web_url("button_next.gif", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=menus", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/login.pl", 
		"Snapshot=t5.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("afterReg",LR_AUTO);

	lr_start_transaction("signOff");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(42);

	web_url("SignOff Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t6.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("signOff",LR_AUTO);

	lr_start_transaction("login");

	web_revert_auto_header("Sec-Fetch-User");

	web_add_header("Origin", 
		"http://localhost:1080");

	lr_think_time(37);

	web_submit_data("login.pl_4", 
		"Action=http://localhost:1080/cgi-bin/login.pl", 
		"Method=POST", 
		"TargetFrame=info", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?in=home", 
		"Snapshot=t7.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=userSession", "Value=135565.54127177zQHDVfcpfcQVzzzHtViDipQVfVHf", ENDITEM, 
		"Name=username", "Value=jojo", ENDITEM, 
		"Name=password", "Value=bean", ENDITEM, 
		"Name=login.x", "Value=75", ENDITEM, 
		"Name=login.y", "Value=2", ENDITEM, 
		"Name=JSFormSubmit", "Value=off", ENDITEM, 
		LAST);

	lr_end_transaction("login",LR_AUTO);

	lr_start_transaction("itinerary");

	web_add_auto_header("Sec-Fetch-User", 
		"?1");

	lr_think_time(38);

	web_url("Itinerary Button", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?page=itinerary", 
		"TargetFrame=body", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=home", 
		"Snapshot=t8.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("itinerary",LR_AUTO);

	lr_start_transaction("deleteBooking");

	web_add_auto_header("Origin", 
		"http://localhost:1080");

	lr_think_time(172);

	web_submit_data("itinerary.pl", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t9.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=210297416-100265-JB", ENDITEM, 
		"Name=flightID", "Value=210297416-177189-JB", ENDITEM, 
		"Name=flightID", "Value=210297424-254142-JB", ENDITEM, 
		"Name=flightID", "Value=210297424-331066-JB", ENDITEM, 
		"Name=5", "Value=on", ENDITEM, 
		"Name=flightID", "Value=33492785-41-JB", ENDITEM, 
		"Name=flightID", "Value=0-4-M", ENDITEM, 
		"Name=flightID", "Value=0-0-", ENDITEM, 
		"Name=flightID", "Value=8-62-", ENDITEM, 
		"Name=flightID", "Value=38-6923-j", ENDITEM, 
		"Name=flightID", "Value=0-0-jj", ENDITEM, 
		"Name=flightID", "Value=8-85-", ENDITEM, 
		"Name=flightID", "Value=38-9553-j", ENDITEM, 
		"Name=flightID", "Value=0-1-jj", ENDITEM, 
		"Name=flightID", "Value=0-10-", ENDITEM, 
		"Name=flightID", "Value=0-11-", ENDITEM, 
		"Name=flightID", "Value=0-123-1C", ENDITEM, 
		"Name=flightID", "Value=0-13-J", ENDITEM, 
		"Name=flightID", "Value=0-13854-03", ENDITEM, 
		"Name=flightID", "Value=45724736711-146-JB", ENDITEM, 
		"Name=flightID", "Value=0-154-J", ENDITEM, 
		"Name=flightID", "Value=0-162-J", ENDITEM, 
		"Name=flightID", "Value=0-170-J", ENDITEM, 
		"Name=flightID", "Value=0-177-J", ENDITEM, 
		"Name=flightID", "Value=0-185-J", ENDITEM, 
		"Name=flightID", "Value=0-193-J", ENDITEM, 
		"Name=flightID", "Value=0-200-J", ENDITEM, 
		"Name=flightID", "Value=0-208-J", ENDITEM, 
		"Name=flightID", "Value=0-216-J", ENDITEM, 
		"Name=flightID", "Value=0-223-J", ENDITEM, 
		"Name=flightID", "Value=0-231-J", ENDITEM, 
		"Name=flightID", "Value=0-239-J", ENDITEM, 
		"Name=flightID", "Value=0-246-J", ENDITEM, 
		"Name=flightID", "Value=0-254-J", ENDITEM, 
		"Name=flightID", "Value=0-262-J", ENDITEM, 
		"Name=flightID", "Value=0-270-J", ENDITEM, 
		"Name=flightID", "Value=0-277-J", ENDITEM, 
		"Name=flightID", "Value=0-285-J", ENDITEM, 
		"Name=flightID", "Value=0-293-J", ENDITEM, 
		"Name=flightID", "Value=0-300-J", ENDITEM, 
		"Name=flightID", "Value=0-308-J", ENDITEM, 
		"Name=flightID", "Value=0-316-J", ENDITEM, 
		"Name=flightID", "Value=0-323-J", ENDITEM, 
		"Name=flightID", "Value=0-331-J", ENDITEM, 
		"Name=flightID", "Value=0-339-J", ENDITEM, 
		"Name=flightID", "Value=0-346-J", ENDITEM, 
		"Name=flightID", "Value=0-354-J", ENDITEM, 
		"Name=flightID", "Value=0-362-J", ENDITEM, 
		"Name=flightID", "Value=0-370-J", ENDITEM, 
		"Name=flightID", "Value=0-377-J", ENDITEM, 
		"Name=flightID", "Value=0-385-J", ENDITEM, 
		"Name=flightID", "Value=0-39-J", ENDITEM, 
		"Name=removeFlights.x", "Value=75", ENDITEM, 
		"Name=removeFlights.y", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=33", ENDITEM, 
		"Name=.cgifields", "Value=32", ENDITEM, 
		"Name=.cgifields", "Value=21", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=26", ENDITEM, 
		"Name=.cgifields", "Value=17", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=18", ENDITEM, 
		"Name=.cgifields", "Value=30", ENDITEM, 
		"Name=.cgifields", "Value=16", ENDITEM, 
		"Name=.cgifields", "Value=44", ENDITEM, 
		"Name=.cgifields", "Value=27", ENDITEM, 
		"Name=.cgifields", "Value=25", ENDITEM, 
		"Name=.cgifields", "Value=28", ENDITEM, 
		"Name=.cgifields", "Value=40", ENDITEM, 
		"Name=.cgifields", "Value=20", ENDITEM, 
		"Name=.cgifields", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=49", ENDITEM, 
		"Name=.cgifields", "Value=24", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=31", ENDITEM, 
		"Name=.cgifields", "Value=35", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=48", ENDITEM, 
		"Name=.cgifields", "Value=42", ENDITEM, 
		"Name=.cgifields", "Value=22", ENDITEM, 
		"Name=.cgifields", "Value=46", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=23", ENDITEM, 
		"Name=.cgifields", "Value=29", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=50", ENDITEM, 
		"Name=.cgifields", "Value=39", ENDITEM, 
		"Name=.cgifields", "Value=36", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=51", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=41", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=47", ENDITEM, 
		"Name=.cgifields", "Value=15", ENDITEM, 
		"Name=.cgifields", "Value=38", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=34", ENDITEM, 
		"Name=.cgifields", "Value=45", ENDITEM, 
		"Name=.cgifields", "Value=37", ENDITEM, 
		"Name=.cgifields", "Value=43", ENDITEM, 
		"Name=.cgifields", "Value=19", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("deleteBooking",LR_AUTO);

	lr_think_time(74);

	lr_start_transaction("deleteAllBookings");

	web_submit_data("itinerary.pl_2", 
		"Action=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Method=POST", 
		"TargetFrame=", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/itinerary.pl", 
		"Snapshot=t10.inf", 
		"Mode=HTML", 
		ITEMDATA, 
		"Name=flightID", "Value=210297416-100265-JB", ENDITEM, 
		"Name=flightID", "Value=210297416-177189-JB", ENDITEM, 
		"Name=flightID", "Value=210297424-254142-JB", ENDITEM, 
		"Name=flightID", "Value=210297424-331066-JB", ENDITEM, 
		"Name=flightID", "Value=0-3-M", ENDITEM, 
		"Name=flightID", "Value=0-46-&&", ENDITEM, 
		"Name=flightID", "Value=0-54653-j", ENDITEM, 
		"Name=flightID", "Value=0-6-j", ENDITEM, 
		"Name=flightID", "Value=8-7192-", ENDITEM, 
		"Name=flightID", "Value=0-7-jj", ENDITEM, 
		"Name=flightID", "Value=420114-0-JB", ENDITEM, 
		"Name=flightID", "Value=0-9-", ENDITEM, 
		"Name=flightID", "Value=0-10008-J", ENDITEM, 
		"Name=flightID", "Value=0-1-JB", ENDITEM, 
		"Name=flightID", "Value=0-11-\r\n", ENDITEM, 
		"Name=flightID", "Value=0-12-11", ENDITEM, 
		"Name=flightID", "Value=0-13-11", ENDITEM, 
		"Name=flightID", "Value=0-13-11", ENDITEM, 
		"Name=flightID", "Value=0-14-11", ENDITEM, 
		"Name=flightID", "Value=0-15-11", ENDITEM, 
		"Name=flightID", "Value=0-16-11", ENDITEM, 
		"Name=flightID", "Value=0-16-51", ENDITEM, 
		"Name=flightID", "Value=0-17-\r\n", ENDITEM, 
		"Name=flightID", "Value=0-18-\r\n", ENDITEM, 
		"Name=flightID", "Value=36-19-31", ENDITEM, 
		"Name=flightID", "Value=3-20-11", ENDITEM, 
		"Name=flightID", "Value=2-20-11", ENDITEM, 
		"Name=flightID", "Value=1-21-11", ENDITEM, 
		"Name=flightID", "Value=1-22-11", ENDITEM, 
		"Name=flightID", "Value=2-23-11", ENDITEM, 
		"Name=flightID", "Value=2-23-11", ENDITEM, 
		"Name=flightID", "Value=3-24-11", ENDITEM, 
		"Name=flightID", "Value=3-25-11", ENDITEM, 
		"Name=flightID", "Value=1-26-11", ENDITEM, 
		"Name=flightID", "Value=1-26-11", ENDITEM, 
		"Name=flightID", "Value=0-27-11", ENDITEM, 
		"Name=flightID", "Value=2-28-11", ENDITEM, 
		"Name=flightID", "Value=0-29-11", ENDITEM, 
		"Name=flightID", "Value=2-30-11", ENDITEM, 
		"Name=flightID", "Value=2-30-11", ENDITEM, 
		"Name=flightID", "Value=1-31-11", ENDITEM, 
		"Name=flightID", "Value=2-32-11", ENDITEM, 
		"Name=flightID", "Value=3-33-11", ENDITEM, 
		"Name=flightID", "Value=2-33-11", ENDITEM, 
		"Name=flightID", "Value=2-34-11", ENDITEM, 
		"Name=flightID", "Value=0-35-11", ENDITEM, 
		"Name=flightID", "Value=0-36-11", ENDITEM, 
		"Name=removeAllFlights.x", "Value=49", ENDITEM, 
		"Name=removeAllFlights.y", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=33", ENDITEM, 
		"Name=.cgifields", "Value=32", ENDITEM, 
		"Name=.cgifields", "Value=21", ENDITEM, 
		"Name=.cgifields", "Value=7", ENDITEM, 
		"Name=.cgifields", "Value=26", ENDITEM, 
		"Name=.cgifields", "Value=17", ENDITEM, 
		"Name=.cgifields", "Value=2", ENDITEM, 
		"Name=.cgifields", "Value=1", ENDITEM, 
		"Name=.cgifields", "Value=18", ENDITEM, 
		"Name=.cgifields", "Value=30", ENDITEM, 
		"Name=.cgifields", "Value=16", ENDITEM, 
		"Name=.cgifields", "Value=44", ENDITEM, 
		"Name=.cgifields", "Value=27", ENDITEM, 
		"Name=.cgifields", "Value=25", ENDITEM, 
		"Name=.cgifields", "Value=28", ENDITEM, 
		"Name=.cgifields", "Value=40", ENDITEM, 
		"Name=.cgifields", "Value=20", ENDITEM, 
		"Name=.cgifields", "Value=14", ENDITEM, 
		"Name=.cgifields", "Value=24", ENDITEM, 
		"Name=.cgifields", "Value=10", ENDITEM, 
		"Name=.cgifields", "Value=31", ENDITEM, 
		"Name=.cgifields", "Value=35", ENDITEM, 
		"Name=.cgifields", "Value=11", ENDITEM, 
		"Name=.cgifields", "Value=42", ENDITEM, 
		"Name=.cgifields", "Value=22", ENDITEM, 
		"Name=.cgifields", "Value=46", ENDITEM, 
		"Name=.cgifields", "Value=13", ENDITEM, 
		"Name=.cgifields", "Value=23", ENDITEM, 
		"Name=.cgifields", "Value=29", ENDITEM, 
		"Name=.cgifields", "Value=6", ENDITEM, 
		"Name=.cgifields", "Value=39", ENDITEM, 
		"Name=.cgifields", "Value=36", ENDITEM, 
		"Name=.cgifields", "Value=3", ENDITEM, 
		"Name=.cgifields", "Value=9", ENDITEM, 
		"Name=.cgifields", "Value=41", ENDITEM, 
		"Name=.cgifields", "Value=12", ENDITEM, 
		"Name=.cgifields", "Value=47", ENDITEM, 
		"Name=.cgifields", "Value=15", ENDITEM, 
		"Name=.cgifields", "Value=38", ENDITEM, 
		"Name=.cgifields", "Value=8", ENDITEM, 
		"Name=.cgifields", "Value=4", ENDITEM, 
		"Name=.cgifields", "Value=34", ENDITEM, 
		"Name=.cgifields", "Value=45", ENDITEM, 
		"Name=.cgifields", "Value=37", ENDITEM, 
		"Name=.cgifields", "Value=43", ENDITEM, 
		"Name=.cgifields", "Value=19", ENDITEM, 
		"Name=.cgifields", "Value=5", ENDITEM, 
		LAST);

	lr_end_transaction("deleteAllBookings",LR_AUTO);

	lr_start_transaction("logout");

	web_revert_auto_header("Origin");

	web_revert_auto_header("Sec-Fetch-User");

	lr_think_time(18);

	web_url("welcome.pl_2", 
		"URL=http://localhost:1080/cgi-bin/welcome.pl?signOff=1", 
		"TargetFrame=", 
		"Resource=0", 
		"RecContentType=text/html", 
		"Referer=http://localhost:1080/cgi-bin/nav.pl?page=menu&in=itinerary", 
		"Snapshot=t11.inf", 
		"Mode=HTML", 
		LAST);

	lr_end_transaction("logout",LR_AUTO);

	return 0;
}