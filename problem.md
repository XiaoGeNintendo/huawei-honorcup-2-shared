

<!DOCTYPE HTML PUBLIC "-//W3C//DTD HTML 4.01//EN">
<html lang="en">
<head>
    <meta http-equiv="content-type" content="text/html; charset=UTF-8">
    <meta name="X-Csrf-Token" content="828b6f178230700222bd6c25319a66e2"/>
    <meta id="viewport" name="viewport" content="width=device-width, initial-scale=0.01"/>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery-1.8.3.js"></script>
    <script type="application/javascript">
        window.standaloneContest = false;
        function adjustViewport() {
            var screenWidthPx = Math.min($(window).width(), window.screen.width);
            var siteWidthPx = 1100; // min width of site
            var ratio = Math.min(screenWidthPx / siteWidthPx, 1.0);
            var viewport = "width=device-width, initial-scale=" + ratio;
            $('#viewport').attr('content', viewport);
            var style = $('<style>html * { max-height: 1000000px; }</style>');
            $('html > head').append(style);
        }

        if ( /Android|webOS|iPhone|iPad|iPod|BlackBerry/i.test(navigator.userAgent) ) {
            adjustViewport();
        }
    </script>
    <meta http-equiv="pragma" content="no-cache">
    <meta http-equiv="expires" content="-1">
    <meta http-equiv="profileName" content="e2">
    <meta name="google-site-verification" content="OTd2dN5x4nS4OPknPI9JFg36fKxjqY0i1PSfFPv_J90"/>
    <meta property="fb:admins" content="100001352546622" />
    <meta property="og:image" content="//sta.codeforces.com/s/88254/images/codeforces-telegram-square.png" />
    <link rel="image_src" href="//sta.codeforces.com/s/88254/images/codeforces-telegram-square.png" />
    <meta property="og:title" content="Problem - A1 - Codeforces"/>
    <meta property="og:description" content=""/>
    
    <meta property="og:site_name" content="Codeforces"/>
    <meta name="uc" content="46520ad171fe7a158ffb8946efee494b37fa4636"/>
    <meta name="usmc" content="fbb0ffcea5a08b552e01e92dfd077e5f572e4819"/>
    
    <meta name="cc" content="0be04e5fba434086c49617501b1fc65adc7ee2a5"/>
    <meta name="pc" content="62dc5cca3edebcc3979529221291f442faae2943"/>
    
    <meta name="utc_offset" content="+03:00"/>
    <meta name="verify-reformal" content="f56f99fd7e087fb6ccb48ef2" />
    <title>Problem - A1 - Codeforces</title>
        <meta name="description" content="Codeforces. Programming competitions and contests, programming community" />
        <meta name="keywords" content="programming algorithm contest competition informatics olympiads c++ java graphs vkcup" />
    <meta name="robots" content="index, follow" />

    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/font-awesome.min.css" type="text/css" charset="utf-8" />

        <link href='//fonts.googleapis.com/css?family=PT+Sans+Narrow:400,700&subset=latin,cyrillic' rel='stylesheet' type='text/css'>
        <link href='//fonts.googleapis.com/css?family=Cuprum&subset=latin,cyrillic' rel='stylesheet' type='text/css'>


    <link rel="shortcut icon" type="image/png" href="//sta.codeforces.com/s/88254/favicon.png">

    <!--CombineResourcesFilter-->
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/prettify.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/clear.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/style.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/ttypography.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/problem-statement.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/second-level-menu.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/roundbox.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/datatable.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/table-form.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/topic.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/jquery.jgrowl.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/facebox.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/jquery.wysiwyg.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/jquery.autocomplete.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/codeforces.datepick.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/colorbox.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/jquery.drafts.css" type="text/css" charset="utf-8" />
        <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/community.css" type="text/css" charset="utf-8" />
        <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/status.css" type="text/css" charset="utf-8" />
        <link rel="stylesheet" href="//sta.codeforces.com/s/88254/css/sidebar-menu.css" type="text/css" charset="utf-8" />

    <!-- MathJax -->
    <script type="text/x-mathjax-config">
    MathJax.Hub.Config({
      tex2jax: {inlineMath: [['$$$','$$$']], displayMath: [['$$$$$$','$$$$$$']]}
    });
    </script>
    <script type="text/javascript" async
            src="https://assets.codeforces.com/mathjax/MathJax.js?config=TeX-AMS_HTML-full"
    >
    </script>
    <!-- /MathJax -->

    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/prettify/prettify.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/moment-with-locales.min.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/pushstream.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.easing.min.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.lavalamp.min.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.jgrowl.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.swipe.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/facebox.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.wysiwyg.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/controls/wysiwyg.colorpicker.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/controls/wysiwyg.table.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/controls/wysiwyg.image.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/controls/wysiwyg.link.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.autocomplete.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/ua-parser.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.datepick.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.ie6blocker.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.colorbox-min.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.ba-bbq.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/jquery.drafts.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/clipboard.min.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/autosize.min.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/sjcl.js"></script>
    <script type="text/javascript" src="/scripts/ef3c5684784c97c5e26d334deb8c4adc/en/codeforces-options.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/codeforces.js?v=20160131"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/EventCatcher.js?v=20160131"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/js/preparedVerdictFormats-en.js"></script>
    <!--/CombineResourcesFilter-->

    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/markitup/skins/markitup/style.css" type="text/css" charset="utf-8" />
    <link rel="stylesheet" href="//sta.codeforces.com/s/88254/markitup/sets/markdown/style.css" type="text/css" charset="utf-8" />


    <script type="text/javascript" src="//sta.codeforces.com/s/88254/markitup/jquery.markitup.js"></script>
    <script type="text/javascript" src="//sta.codeforces.com/s/88254/markitup/sets/markdown/set.js"></script>

    <!--[if IE]>
    <style>
        #sidebar {
            padding-left: 1em;
            margin: 1em 1em 1em 0;
        }
    </style>
    <![endif]-->


        <script id="nocomb.ace-builds/ace.js" src="//sta.codeforces.com/s/88254/js/ace-builds/ace.js" type="text/javascript"></script>
        <script id="nocomb.ace-builds/ext-language_tools.js" src="//sta.codeforces.com/s/88254/js/ace-builds/ext-language_tools.js" type="text/javascript"></script>
        <script id="nocomb.ace-builds/ext-modelist.js" src="//sta.codeforces.com/s/88254/js/ace-builds/ext-modelist.js" type="text/javascript"></script>

</head>
<body><span style='display:none;' class='csrf-token' data-csrf='828b6f178230700222bd6c25319a66e2'>&nbsp;</span>
<div class="button-up" style="display: none; opacity: 0.7; width: 50px; height:100%; position: fixed; left: 0; top: 0; cursor: pointer; text-align: center; line-height: 35px; color: #d3dbe4; font-weight: bold; font-size: 3.0rem;"><i class="icon-circle-arrow-up"></i></div>
<div class="verdictPrototypeDiv" style="display: none;"></div>

<!-- Codeforces JavaScripts. -->
<script type="text/javascript">
    String.prototype.hashCode = function() {
        var hash = 0, i, chr;
        if (this.length === 0) return hash;
        for (i = 0; i < this.length; i++) {
            chr   = this.charCodeAt(i);
            hash  = ((hash << 5) - hash) + chr;
            hash |= 0; // Convert to 32bit integer
        }
        return hash;
    };

    var queryMobile = Codeforces.queryString.mobile;
    if (queryMobile === "true" || queryMobile === "false") {
        Codeforces.putToStorage("useMobile", queryMobile == "true");
    } else {
        var useMobile = Codeforces.getFromStorage("useMobile");
        if (useMobile === true || useMobile === false) {
            if (useMobile != false) {
                Codeforces.redirect(Codeforces.updateUrlParameter(document.location.href, "mobile", useMobile));
            }
        }
    }
</script>
<script type="text/javascript">
    if (window.parent.frames.length > 0) {
        window.stop();
    }
</script>


<script type="text/javascript">
    window.fbAsyncInit = function() {
        FB.init({
            appId      : '554666954583323',
            xfbml      : true,
            version    : 'v2.8'
        });
        FB.AppEvents.logPageView();
    };

    (function(d, s, id){
        var js, fjs = d.getElementsByTagName(s)[0];
        if (d.getElementById(id)) {return;}
        js = d.createElement(s); js.id = id;
        js.src = "//connect.facebook.net/en_US/sdk.js";
        fjs.parentNode.insertBefore(js, fjs);
    }(document, 'script', 'facebook-jssdk'));
</script>


    <script type="text/javascript">
        $(document).ready(function () {
    (function () {
        jQuery.expr[':'].containsCI = function(elem, index, match) {
            return !match || !match.length || match.length < 4 || !match[3] || (
                    elem.textContent || elem.innerText || jQuery(elem).text() || ''
            ).toLowerCase().indexOf(match[3].toLowerCase()) >= 0;
        }
    }(jQuery));

    $.ajaxPrefilter(function(options, originalOptions, xhr) {
        var csrf = Codeforces.getCsrfToken();

        if (csrf) {
            var data = originalOptions.data;
            if (originalOptions.data !== undefined) {
                if (Object.prototype.toString.call(originalOptions.data) === '[object String]') {
                    data = $.deparam(originalOptions.data);
                }
            } else {
                data = {};
            }
            options.data = $.param($.extend(data, { csrf_token: csrf }));
        }
    });

    window.getCodeforcesServerTime = function(callback) {
        $.post("/data/time", {}, callback, "json");
    }

    window.updateTypography = function () {
        $("div.ttypography code").addClass("tt");
        $("div.ttypography pre>code").addClass("prettyprint").removeClass("tt");
        $("div.ttypography table").addClass("bordertable");
        prettyPrint();
    }

    $.ajaxSetup({ scriptCharset: "utf-8" ,contentType: "application/x-www-form-urlencoded; charset=UTF-8", headers: {
        'X-Csrf-Token': Codeforces.getCsrfToken()
    }});

    window.updateTypography();

    Codeforces.signForms();

    setTimeout(function() {
        $(".second-level-menu-list").lavaLamp({
            fx: "backout",
            speed: 700
        });
    }, 100);


    Codeforces.countdown();
    $("a[rel='photobox']").colorbox();

        var count = 0;

        function getDelay() {
            var delay = 0;
            var last = Codeforces.getFromStorage("LastOnlineTimeUpdaterMillis", 0);
            if (last && last != null) {
                var period = count < 20 ? 180 * 1000 : 360 * 1000;
                delay = period - (new Date().getTime() - last);
                if (delay < 0)
                    delay = 0;
            }
            return delay;
        }

        window.setInterval(function () {
            if (getDelay() <= 0 && count < 120) {
                ++count;
                Codeforces.ping("/data/update-online");
            }
        }, 5000);

        var handle = "gwq2017";
        $("a.rated-user:contains(" + handle + "), span.participant:contains(" + handle + ")").each(function () {
            if ($(this).text() == handle) {
                var td = $(this).parent();
                var tr = $(this).parent().parent();
                if (td.is("td") && tr.is("tr")) {
                    tr.addClass("highlighted-row");
                }
            }
        });

    function showAnnouncements(json) {
        //info("j=" + JSON.stringify(json));

        if (json.t != "a") {
            return;
        }
        // console.log("Got announcement from channel");
        setTimeout(function() {
            Codeforces.showAnnouncements(json.d, "en");
        }, Math.random() * 500);
    }

    function showEventCatcherUserMessage(json) {
        if (json.t == "s") {
            var points = json.d[5];
            var passedTestCount = json.d[7];
            var judgedTestCount = json.d[8];
            var verdict = preparedVerdictFormats[json.d[12]];
            var verdictPrototypeDiv = $(".verdictPrototypeDiv");
            verdictPrototypeDiv.html(verdict);
            if (judgedTestCount != null && judgedTestCount != undefined) {
                verdictPrototypeDiv.find(".verdict-format-judged").text(judgedTestCount);
            }
            if (passedTestCount != null && passedTestCount != undefined) {
                verdictPrototypeDiv.find(".verdict-format-passed").text(passedTestCount);
            }
            if (points != null && points != undefined) {
                verdictPrototypeDiv.find(".verdict-format-points").text(points);
            }
            Codeforces.showMessage(verdictPrototypeDiv.text());
        }
    }

    $(".clickable-title").each(function() {
        var title = $(this).attr("data-title");
        if (title) {
            var tmp = document.createElement("DIV");
            tmp.innerHTML = title;
            $(this).attr("title", tmp.textContent || tmp.innerText || "");
        }
    });

    $(".clickable-title").click(function() {
        var title = $(this).attr("data-title");
        if (title) {
            Codeforces.alert(title);
        } else {
            Codeforces.alert($(this).attr("title"));
        }
    }).css("position", "relative").css("bottom", "3px");


    Codeforces.reformatTimes();

    //Codeforces.initializePubSub();
    if (window.codeforcesOptions.subscribeServerUrl) {
        window.eventCatcher = new EventCatcher(
            window.codeforcesOptions.subscribeServerUrl,
            [
                Codeforces.getGlobalChannel(),
                Codeforces.getUserChannel(),
                Codeforces.getUserShowMessageChannel(),
                Codeforces.getContestChannel(),
                Codeforces.getParticipantChannel(),
                Codeforces.getTalkChannel()
            ]
        );

        if (Codeforces.getParticipantChannel()) {
            window.eventCatcher.subscribe(Codeforces.getParticipantChannel(), function(json) {
                showAnnouncements(json);
            });
        }

        if (Codeforces.getContestChannel()) {
            window.eventCatcher.subscribe(Codeforces.getContestChannel(), function(json) {
                showAnnouncements(json);
            });
        }

        if (Codeforces.getGlobalChannel()) {
            window.eventCatcher.subscribe(Codeforces.getGlobalChannel(), function(json) {
                showAnnouncements(json);
            });
        }

        if (Codeforces.getUserChannel()) {
            window.eventCatcher.subscribe(Codeforces.getUserChannel(), function(json) {
                showAnnouncements(json);
            });
        }

        if (Codeforces.getUserShowMessageChannel()) {
            window.eventCatcher.subscribe(Codeforces.getUserShowMessageChannel(), function(json) {
                showEventCatcherUserMessage(json);
            });
        }
    }

    Codeforces.setupContestTimes("/data/contests");
    Codeforces.setupSpoilers();
    Codeforces.setupTutorials("/data/problemTutorial");
        });
    </script>

<script type="text/javascript">
  var _gaq = _gaq || [];
  _gaq.push(['_setAccount', 'UA-743380-5']);
  _gaq.push(['_trackPageview']);

  (function () {
    var ga = document.createElement('script'); ga.type = 'text/javascript'; ga.async = true;
    ga.src = (document.location.protocol == 'https:' ? 'https://ssl' : 'http://www') + '.google-analytics.com/ga.js';
    var s = document.getElementsByTagName('script')[0]; s.parentNode.insertBefore(ga, s);
  })();
</script>


<div id="body">
            <script type="application/javascript">
                window.setTimeout(function () {
                    var url = location.href;
                    var hashCode32 = Math.abs(url.hashCode()).toString();
                    var hashCode = "p" + hashCode32 + Math.abs((hashCode32 + url).hashCode());
                    var pvs = Codeforces.getFromStorage("pvs" + hashCode);
                    if (!pvs) {
                        $.post("/data/apv", {
                            ftaa: window._ftaa,
                            bfaa: window._bfaa,
                            url: url
                        }, function (json) {
                            if (json["success"] === "true") {
                                Codeforces.putToStorage("pvs" + hashCode, true);
                            }
                        }, "json");
                    }
                }, 5000);
            </script>
        

<div class="side-bell" style="visibility: hidden; display: none; opacity: 0.7; width: 40px; position: fixed; right: 0; top: 0; cursor: pointer; text-align: center; line-height: 35px; color: #d3dbe4; font-weight: bold; font-size: 1.5rem;">
    <span class="icon-stack" style="width: 100%;">
        <i class="icon-circle icon-stack-base"></i>
        <i class="icon-bell-alt icon-light"></i>
    </span>
    <br/>
    <span class="side-bell__count" style="position: relative; top: -10px;"></span>
</div>


<div class="header-bell" style="display: none;">
    <div class="header-bell__img"><span class="header-bell__count"></span></div>

    <div class="bell-details">
        <div class="bell-details__proto-row-comment">
            <a class="bell-details__thumbnail-a" href="#"><img src=""/></a>
            <div class="bell-details__comment"></div>
            <div class="bell-details__time"></div>
        </div>
        <div class="bell-details__proto-row-blog-entry">
            <a class="bell-details__thumbnail-a" href="#"><img src=""/></a>
            <div class="bell-details__blog-entry"></div>
            <div class="bell-details__time"></div>
        </div>
        <div class="bell-details__proto-row-comment-reply">
            <a class="bell-details__thumbnail-a" href="#"><img src=""/></a>
            <div class="bell-details__comment-reply"></div>
        </div>

        <div class="bell-details__no-new">
            There are no new notifications
        </div>

        <div class="bell-details__recent-link">
            <a href="/notifications">History (at most 100 notifications)</a>
        </div>
    </div>
</div>

<style>
    .header-bell {
        display: inline-block;
        position: relative;
        cursor: pointer;
    }

    .header-bell__img {
        opacity: 0.5;
        background-image: url("//sta.codeforces.com/s/88254/images/icons/bell_inactive-20x20.png");
        position: relative;
        bottom: 1px;
        width: 20px;
        height: 20px;
    }

    .header-bell__img-active  {
        opacity: 1 !important;
        background-image: url("//sta.codeforces.com/s/88254/images/icons/bell_active-20x20.png") !important;
    }

    .header-bell__count {
        position: absolute;
        top: 8px;
        left: 18px;
        font-weight: bold;
        font-size: 10px;
    }

    .bell-details {
        display: none;
        z-index: 5;
        border: 1px solid rgb(185, 185, 185);
        width: 40rem;
        max-height: 60rem;
        padding: 0;
        position: absolute;
        top: 20px;
        right: 0;
        background-color: white;
        overflow: scroll;
        overflow-x: hidden;
        overflow-y: auto;
    }
    .bell-details.sidebar-bell {
        position: fixed;
        right: 50px;
    }

    .bell-details__no-new {
        font-size: 1.3rem;
        display: block;
        text-align: center;
        color: #888 !important;
        padding: 1em;
    }

    .bell-details__recent-link {
        margin: 0;
        padding: 0.5em;
        text-align: center;
        border-top: 1px solid rgb(185, 185, 185);
    }

    .bell-details__recent-link a {
        font-size: 1.2rem;
    }

    .bell-details__proto-row-comment {
        display: none;
    }

    .bell-details__proto-row-blog-entry {
        display: none;
    }

    .bell-details__proto-row-comment-reply {
        display: none;
    }

    .bell-details__row {
        text-align: left;
        margin: 0.5em;
        padding: 0.25em 0.25em 0.75em 0.25em;
        clear: both;
    }

    .bell-details__row:hover {
        cursor: pointer;
        background-color: #def;
    }

    .bell-details__row-active {
        background-color: #def;
    }

    .bell-details__thumbnail-a {
        text-decoration: none;
    }

    .bell-details__row img {
        zoom: 50%;
        margin-right: 2em;
        float: left;
    }

    .bell-details__comment {
        padding-left: 45px;
        font-size: 1.3rem;
    }

    .bell-details__blog-entry {
        padding-left: 45px;
        font-size: 1.3rem;
    }

    .bell-details__comment-reply {
        padding-left: 45px;
        font-size: 1.3rem;
    }

    .bell-details__time {
        padding-left: 45px;
        margin-top: 0.2em;
        font-size: 1.1rem;
        color: #888 !important;
    }
</style>

<script>
    $(function () {
        if ($(window).width() < 1600) {
            $('.side-bell').css('width', '30px').css('line-height', '30px').css('font-size', '10px');
        }

        if ($(window).width() >= 1200) {
            $ (window).scroll (function () {
                if ($ (this).scrollTop () > 100) {
                    $(".bell-details").addClass("sidebar-bell");
                    $ ('.side-bell').fadeIn();
                } else {
                    $(".bell-details").removeClass("sidebar-bell");
                    $ ('.side-bell').fadeOut();
                }
            });

            $('.side-bell').hover(function () {
                $(this).animate({
                    'opacity':'1'
                }).css({'color':'#6a86a4'});
            }, function () {
                $(this).animate({
                    'opacity':'0.7'
                }).css({'color':'#d3dbe4'});
            });
        }

        $(".lang-chooser>div:first-child").prepend($("<span style='position: relative; bottom: 8px; padding: 0 0.5em;'>|</span>")).prepend($(".header-bell").show());
        function Bell() {
            var bell = this;
            var notifications = JSON.parse("[]");

            bell.notifications = {};

            for (var i in notifications) {
                if (notifications.hasOwnProperty(i)) {
                    bell.notifications[notifications[i].id] = notifications[i];
                }
            }

            function onClick(notification) {
                var notificationIds = [];
                var reason = notification.data.reasonType + "#" + notification.reasonId;
                for (id in bell.notifications) {
                    if (bell.notifications.hasOwnProperty(id)) {
                        var otherNotification = bell.notifications[id];
                        var otherReason = otherNotification.data.reasonType + "#" + otherNotification.reasonId;
                        if (otherReason == reason) {
                            notificationIds.push(otherNotification.id);
                        }
                    }
                }
                $.post("/data/notification", {action: "markAsRead", notificationIds: notificationIds.join(",")}, function(result) {
                    Codeforces.redirect(notification.data.url);
                }, "json");
            }

            var $bellDetails = $(".bell-details");
            bell.newCommentRow = function (notification) {
                var row = $(".bell-details__proto-row-comment").clone();
                row.addClass("bell-details__row").attr("data-notificationId", notification.id);
                row.find(".bell-details__thumbnail-a").attr("href", notification.data.reasonUserUrl);
                row.find("img").attr("src", notification.data.reasonUserThumbnailUrl);
                row.find(".bell-details__comment").html(
                        "ReasonUser mentioned you in a comment".replace("ReasonUser", notification.data.reasonUserHtml)
                );
                row.find(".bell-details__time").html(
                        "<span class='format-systemtimewithseconds'>"
                        + notification.creationTimeString
                        + "</span>"
                );
                row.removeClass("bell-details__proto-row-comment");
                row.click(function() {
                    onClick(notification);
                    return false;
                });
                return row;
            };
            bell.newFriendCommentRow = function (notification) {
                var row = $(".bell-details__proto-row-comment").clone();
                row.addClass("bell-details__row").attr("data-notificationId", notification.id);
                row.find(".bell-details__thumbnail-a").attr("href", notification.data.reasonUserUrl);
                row.find("img").attr("src", notification.data.reasonUserThumbnailUrl);
                row.find(".bell-details__comment").html(
                        "ReasonUser wrote a comment".replace("ReasonUser", notification.data.reasonUserHtml)
                );
                row.find(".bell-details__time").html(
                        "<span class='format-systemtimewithseconds'>"
                        + notification.creationTimeString
                        + "</span>"
                );
                row.removeClass("bell-details__proto-row-comment");
                row.click(function() {
                    onClick(notification);
                    return false;
                });
                return row;
            };
            bell.newCommentReplyRow = function (notification) {
                var row = $(".bell-details__proto-row-comment-reply").clone();
                row.addClass("bell-details__row").attr("data-notificationId", notification.id);
                row.find(".bell-details__thumbnail-a").attr("href", notification.data.reasonUserUrl);
                row.find("img").attr("src", notification.data.reasonUserThumbnailUrl);
                row.find(".bell-details__comment-reply").html(
                        "ReasonUser replied to your comment".replace("ReasonUser", notification.data.reasonUserHtml)
                );
                row.find(".bell-details__time").html(
                        "<span class='format-systemtimewithseconds'>"
                        + notification.creationTimeString
                        + "</span>"
                );
                row.removeClass("bell-details__proto-row-comment-reply");
                row.click(function() {
                    onClick(notification);
                    return false;
                });
                return row;
            };
            bell.newBlogEntryRow = function (notification) {
                var row = $(".bell-details__proto-row-blog-entry").clone();
                row.addClass("bell-details__row").attr("data-notificationId", notification.id);
                row.find(".bell-details__thumbnail-a").attr("href", notification.data.reasonUserUrl);
                row.find("img").attr("src", notification.data.reasonUserThumbnailUrl);
                row.find(".bell-details__blog-entry").html(
                        "ReasonUser mentioned you in a blog entry".replace("ReasonUser", notification.data.reasonUserHtml)
                );
                row.find(".bell-details__time").html(
                        "<span class='format-systemtimewithseconds'>"
                        + notification.creationTimeString
                        + "</span>"
                );
                row.removeClass("bell-details__proto-row-blog-entry");
                row.click(function() {
                    onClick(notification);
                    return false;
                });
                return row;
            };
            bell.newFriendBlogEntryRow = function (notification) {
                var row = $(".bell-details__proto-row-blog-entry").clone();
                row.addClass("bell-details__row").attr("data-notificationId", notification.id);
                row.find(".bell-details__thumbnail-a").attr("href", notification.data.reasonUserUrl);
                row.find("img").attr("src", notification.data.reasonUserThumbnailUrl);
                row.find(".bell-details__blog-entry").html(
                        "ReasonUser wrote a blog entry".replace("ReasonUser", notification.data.reasonUserHtml)
                );
                row.find(".bell-details__time").html(
                        "<span class='format-systemtimewithseconds'>"
                        + notification.creationTimeString
                        + "</span>"
                );
                row.removeClass("bell-details__proto-row-blog-entry");
                row.click(function() {
                    onClick(notification);
                    return false;
                });
                return row;
            };
            bell.newProposalCommentRow = function (notification) {
                var row = $(".bell-details__proto-row-comment-reply").clone();
                row.addClass("bell-details__row").attr("data-notificationId", notification.id);
                row.find(".bell-details__thumbnail-a").attr("href", notification.data.reasonUserUrl);
                row.find("img").attr("src", notification.data.reasonUserThumbnailUrl);
                row.find(".bell-details__comment-reply").html(
                        "ReasonUser commented on ProposalType Proposal".replace("ReasonUser", notification.data.reasonUserHtml)
                                .replace("ProposalType", "Contest" == notification.data.proposalType ? "contest proposal" : "problem proposal")
                                .replace("Proposal", $("<div/>").text(notification.data.proposalName).html())
                );
                row.find(".bell-details__time").html(
                        "<span class='format-systemtimewithseconds'>"
                        + notification.creationTimeString
                        + "</span>"
                );
                row.removeClass("bell-details__proto-row-comment-reply");
                row.click(function() {
                    onClick(notification);
                    return false;
                });
                return row;
            };

            bell.renderRow = function (notification) {
                var $row = $(".bell-details__row[data-notificationId='" + notification.id + "']");

                if ($bellDetails.css("display") != "block" && notification.read) {
                    $row.hide();
                    return;
                }

                notification.data = JSON.parse(notification.dataJson);

                var reason = notification.data.reasonType + "#" + notification.reasonId;

                var has = false;
                $row.each(function () {
                    has = true;
                });
                if ($(".bell-details__row[data-reason='" + reason + "']").length) {
                    has = true;
                }

                if (!has) {
                    $(".side-bell").css("visibility", "visible");
                    var newRow;
                    if (notification.type == "Comment") {
                        newRow = bell.newCommentRow(notification);
                    } else if (notification.type == "BlogEntry") {
                        newRow = bell.newBlogEntryRow(notification);
                    } else if (notification.type == "CommentReply") {
                        newRow = bell.newCommentReplyRow(notification);
                    } else if (notification.type == "FriendComment") {
                        newRow = bell.newFriendCommentRow(notification);
                    } else if (notification.type == "FriendBlogEntry") {
                        newRow = bell.newFriendBlogEntryRow(notification);
                    } else if (notification.type == "ProposalComment") {
                        newRow = bell.newProposalCommentRow(notification)
                    }
                    if (newRow) {
                        newRow.attr("data-reason", reason);
                        $(".bell-details").prepend(newRow);
                    }
                }
            };

            var $count = $(".header-bell__count, .side-bell__count");
            var $img = $(".header-bell__img");
            var $noNew = $(".bell-details__no-new");

            bell.renewCount = function () {
                Codeforces.reformatTimes();
                var count = 0;
                var counted = {};
                for (var id in bell.notifications)
                    if (bell.notifications.hasOwnProperty(id)) {
                        var notification = bell.notifications[id];
                        if (notification) {
                            var reason = notification.data.reasonType + "#" + notification.reasonId;
                            if (!notification.read && !counted[reason]) {
                                count++;
                                counted[reason] = true;
                            }
                        }
                    }
                if (count > 0) {
                    $count.text(count);
                    $img.addClass("header-bell__img-active");
                    $noNew.hide();
                } else {
                    $count.text("");
                    $img.removeClass("header-bell__img-active");
                    if ($bellDetails.css("display") != "block") {
                        $noNew.show();
                    }
                }
            };

            for (var id in bell.notifications)
                if (bell.notifications.hasOwnProperty(id))
                    bell.renderRow(bell.notifications[id]);

            if (window.eventCatcher) {
                window.eventCatcher.subscribe(Codeforces.getUserChannel(), function(json) {
                    if (json.t === "n") {
                        for (var i in json.d)
                            if (json.d.hasOwnProperty(i)) {
                                var notification = json.d[i];
                                notification.data = JSON.parse(notification.dataJson);
                                bell.notifications[notification.id] = notification;
                                bell.renderRow(notification);
                                bell.renewCount();
                            }
                    }
                });
            }


            $(".header-bell, .side-bell").click(function() {
                if ($bellDetails.css("display") == "none") {
                    for (var id in bell.notifications)
                        if (bell.notifications.hasOwnProperty(id))
                            if (bell.notifications[id].read)
                                bell.renderRow(bell.notifications[id]);
                    bell.renewCount();

                    $bellDetails.css("display", "block");

                    var notificationIds = [];
                    for (id in bell.notifications)
                        if (bell.notifications.hasOwnProperty(id))
                            notificationIds.push(id);

                    setTimeout(function() {
                        if ($bellDetails.css("display") == "block") {
                            $.post("/data/notification", {action: "markAsRead", notificationIds: notificationIds.join(",")}, function(result) {
                                // No operations.
                            }, "json");

                            for (var i in notificationIds) {
                                if (notificationIds.hasOwnProperty(i)) {
                                    bell.notifications[notificationIds[i]].read = true;
                                }
                            }
                            bell.renewCount();
                        }
                    }, 2000);
                } else {
                    var has = false;
                    for (var id in bell.notifications) {
                        if (bell.notifications.hasOwnProperty(id) && !bell.notifications[id].read) {
                            has = true;
                        }
                    }
                    if (!has) {
                        $(".side-bell").css("visibility", "hidden");
                    }
                    $bellDetails.css("display", "none");
                    bell.renewCount();
                }
            });
        }

        bell = new Bell();
        bell.renewCount();
    })
</script>

<div id="header" style="position: relative;">
    <div style="float:left;">
            <div><a href="/honorcup"><img src="https://assets.codeforces.com/images/honorcup-marathon-logo.png" style="width:250px;"/></a></div>
    </div>
    <div class="lang-chooser">
        <div style="text-align: right;">
            <a href="?locale=en"><img src="//sta.codeforces.com/s/88254/images/flags/24/gb.png" title="In English" alt="In English"/></a>
            <a href="?locale=ru"><img src="//sta.codeforces.com/s/88254/images/flags/24/ru.png" title="По-русски" alt="По-русски"/></a>
        </div>

        <div >
                        <a href="/profile/gwq2017">gwq2017</a>
                     | 
                        <a href="/713d8d40cc917804bc27de003424b5c6/logout">Logout</a>
                    
        </div>



    </div>
    <br style="clear: both;"/>
</div>
        

    <div class="roundbox menu-box" style="">
            <div class="roundbox-lt">&nbsp;</div>
            <div class="roundbox-rt">&nbsp;</div>
            <div class="roundbox-lb">&nbsp;</div>
            <div class="roundbox-rb">&nbsp;</div>
    <div class="menu-list-container">
    <ul class="menu-list main-menu-list">
                <li class=""><a href="/">Home</a></li>
                <li class=""><a href="/top">Top</a></li>
                <li class="current"><a href="/contests">Contests</a></li>
                <li class=""><a href="/gyms">Gym</a></li>
                <li class=""><a href="/problemset">Problemset</a></li>
                <li class=""><a href="/groups">Groups</a></li>
                <li class=""><a href="/ratings">Rating</a></li>
                <li class=""><a href="/apiHelp">API</a></li>
                <li class=""><a href="/help">Help</a></li>
                <li class=""><a href="/honorcup">Honorcup <img class="icon" src="//st.codeforces.com/images/icons/cup.png"/></a></li>
                <li class=""><a href="/calendar">Calendar</a></li>
    </ul>
        <form method="post" action="/search"><input type='hidden' name='csrf_token' value='828b6f178230700222bd6c25319a66e2'/>
            <input class="search" name="query" data-isPlaceholder="true" value=""/>
        </form>
    <br style="clear: both;"/>
</div>

    </div>

    <script type="text/javascript">
        $(document).ready(function () {
            $("input.search").focus(function () {
                if ($(this).attr("data-isPlaceholder") === "true") {
                    $(this).val("");
                    $(this).removeAttr("data-isPlaceholder");
                }
            });
        });
    </script>
            <br style="height: 3em; clear: both;"/>

        <div style="position: relative;">
                        <div id="sidebar">

    <div class="roundbox sidebox" style="">
            <div class="roundbox-lt">&nbsp;</div>
            <div class="roundbox-rt">&nbsp;</div>
        <table class="rtable ">
            <tbody>
                <tr>
                            <th class="left" style="width:100%;"><a style="color: black" href="/contest/1235">Huawei Honorcup Marathon 2</a></th>
                </tr>
                    <tr>
                                <td class="left  dark" colspan="1"><span class="contest-state-phase">Contest is running</span></td>
                    </tr>
                    <tr>
                                <td class="left " colspan="1"><span class='contest-state-regular countdown before-contest-1235-finish' home='//sta.codeforces.com/s/88254' noRedirection='true' textBeforeRedirect='The coding phase of "Huawei Honorcup Marathon 2" is finished, reload the page to view changes'><span title="318:58:29">13 days</span></span></td>
                    </tr>
                    <tr>
                                <td class="left  dark" colspan="1"><span class="contest-state-regular">Contestant</span></td>
                    </tr>
                    <tr>
                                <td class="left bottom" colspan="1"><span class="contest-state-regular"><center>
    <span>
            <img class="toggle-favourite add-favourite" title="Add to favourites" alt="Add to favourites" data-type="CONTEST" data-entityId="1235" data-size="24" src="//sta.codeforces.com/s/88254/images/icons/star_gray_24.png"/>
    </span>

    <script type="text/javascript">
        $(document).ready(function () {
            $("img.toggle-favourite").click(function () {
                var size = $(this).attr("data-size");
                var img = $(this);

                var isFavourite = !img.hasClass("remove-favourite");
                var type = img.attr("data-type");
                var entityId = img.attr("data-entityId");

                $.post("/data/favourite",
                        { entityId: entityId, type: type, isFavourite: isFavourite },
                        function(response) {
                            if (response["success"] != "true") {
                                alert(response["message"]);
                            } else {
                                if (img.hasClass("remove-favourite")) {
                                    img.attr("src", "//sta.codeforces.com/s/88254/images/icons/star_gray_" + size + ".png");
                                    img.removeClass("remove-favourite");
                                    img.addClass("add-favourite");
                                } else {
                                    img.attr("src", "//sta.codeforces.com/s/88254/images/icons/star_yellow_" + size + ".png");
                                    img.removeClass("add-favourite");
                                    img.addClass("remove-favourite");
                                }
                            }
                        }, "json"
                );

                return false;
            });
        });
    </script>
</center></span></td>
                    </tr>
            </tbody>
        </table>
    </div>

    <div class="roundbox sidebox" style="">
            <div class="roundbox-lt">&nbsp;</div>
            <div class="roundbox-rt">&nbsp;</div>
        <div class="caption titled">&rarr; Languages
            <div class="top-links">
            </div>
        </div>
<div style="margin:1em;">
    <div style="font-size:0.8em;">The following languages are only available languages for the problems from the contest</div><div style="font-weight:bold;margin:0.5em 0;font-size:0.8em;text-align:center;">Huawei Honorcup Marathon 2:</div>
<ul class="list" style="font-size:0.8em;margin-top:0.5em;">
        <li>Text</li>
</ul>
</div>
    </div>

<style type="text/css">
    .submitForm .field {
        font-size: 1.1rem;
        width: 3em !important;
        padding-right: 1em;
    }

    .submitForm input, .submitForm select {
        font-size: 1.1rem;
        width: 17em;
    }
</style>
    <div class="roundbox sidebox" style="">
            <div class="roundbox-lt">&nbsp;</div>
            <div class="roundbox-rt">&nbsp;</div>
        <div class="caption titled">&rarr; Submit?
            <div class="top-links">
            </div>
        </div>
<div>
    <form method="post" action="?csrf_token=828b6f178230700222bd6c25319a66e2" enctype="multipart/form-data" class="submitForm"><input type='hidden' name='csrf_token' value='828b6f178230700222bd6c25319a66e2'/>
        <input type="hidden" name="ftaa" value=""/>
        <input type="hidden" name="bfaa" value=""/>
        <input type="hidden" name="action" value="submitSolutionFormSubmitted"/>
        <input type="hidden" name="submittedProblemIndex" value="A1"/>
        <input type="hidden" name="source" value=""/>

        <table class="table-form" style="width:90%;">
            <tr>
                <td class="field">Language:</td>
                <td>
                    <select name="programTypeId">
                        <option value="57"
                                selected="selected">Text</option>
                    </select>
                </td>
            </tr>
            <tr style="padding: 0; margin: 0; height: 0.5rem;line-height: 1rem;">
                <td style="padding: 0; margin: 0; height: 0.5rem;"></td>
                <td style="padding: 0; margin: 0; height: 0.5rem;">
                    <span class="programTypeNotice notice small" style="position: relative; bottom:7px;">&nbsp;</span>
                </td>
            </tr>

            <tr>
                <td class="field">Choose file:</td>
                <td>
                    <input name="sourceFile" type="file" value=""/>
                </td>
            </tr>

            <tr>
                <td colspan="2">
                    <div style="text-align: center;">



                        <div style="position: relative; display: inline-block;">
                            <input style="width:10em;" class="submit" type="submit" value="Submit"/>
                            <img class="ajax-loading-gif" style="display:none; position: absolute; right:-24px; bottom:0;" src="//sta.codeforces.com/s/88254/images/ajax-loading-24x24.gif"/>
                        </div>
                    </div>
                </td>
            </tr>
        </table>
    </form>
</div>
    </div>

        <script type="text/javascript">
            $(function() {
                window._ftaa = "n/a";
            })
        </script>

        <script type="text/javascript">
            $(function() {
                window._bfaa = "n/a";
            });
        </script>

<script>
    $(function () {
        function adjustNotice(programTypeId) {
            var $programTypeNotice = $(".programTypeNotice");
            $programTypeNotice.text("");
        }

                adjustNotice(57);


        $("select[name='programTypeId']").change(function () {
            adjustNotice(parseInt($(this).val()));
        });

        $(".submit-form, .submitForm").submitOnce(function () {
            var form = $(this);
            var $ftaa = form.find("input[name='ftaa']");
            var $bfaa = form.find("input[name='bfaa']");

            if (window._ftaa && window._bfaa) {
                $ftaa.val(window._ftaa);
                $bfaa.val(window._bfaa);
            }

            if (form.attr("enctype") === "multipart/form-data") {
                var sourceFiles = form.find(".table-form input[name=sourceFile]");

                if (sourceFiles.length === 1 && sourceFiles[0].files && sourceFiles[0].files.length === 0) {
                    form.removeAttr("enctype");
                }
            }

            return true;
        });
    });
</script>

    <div class="roundbox sidebox" style="">
            <div class="roundbox-lt">&nbsp;</div>
            <div class="roundbox-rt">&nbsp;</div>
        <div class="caption titled">&rarr; Last submissions
            <div class="top-links">
            </div>
        </div>
        <table class="rtable smaller">
            <tbody>
                <tr>
                            <th class="left " style="width:2.5em;">Submission</th>
                            <th class=" " style="width:7em;">Time</th>
                            <th class=" ">Verdict</th>
                </tr>
                    <tr>
                                <td class="left bottom "><a href="/contest/1235/submission/61586244">61586244</a></td>
                                <td class="bottom ">Oct/01/2019 08:04</td>
                                <td class="bottom "><span class='verdict-accepted'>Perfect result: <span class=verdict-format-points>60000</span> points</span></td>
                    </tr>
            </tbody>
        </table>
    </div>


    <div class="roundbox sidebox" style="">
            <div class="roundbox-lt">&nbsp;</div>
            <div class="roundbox-rt">&nbsp;</div>
        <div class="caption titled">&rarr; Your points
            <div class="top-links">
            </div>
        </div>
        <table class="rtable smaller">
            <tbody>
                <tr>
                            <th class="left " style="width:2.5em;"></th>
                            <th class=" ">Points</th>
                </tr>
                    <tr>
                                <td class="left  dark "><b>A1</b></td>
                                <td class=" dark "><span class="welldone">60000</span></td>
                    </tr>
                    <tr>
                                <td class="left  "><b>A2</b></td>
                                <td class=" ">442.857</td>
                    </tr>
                    <tr>
                                <td class="left  dark "><b>A3</b></td>
                                <td class=" dark "></td>
                    </tr>
                    <tr>
                                <td class="left  "><b>B1</b></td>
                                <td class=" "><span class="welldone">60000</span></td>
                    </tr>
                    <tr>
                                <td class="left  dark "><b>B2</b></td>
                                <td class=" dark ">113.333</td>
                    </tr>
                    <tr>
                                <td class="left  "><b>B3</b></td>
                                <td class=" "></td>
                    </tr>
                    <tr>
                                <td class="left  dark "><b>C1</b></td>
                                <td class=" dark "><span class="welldone">60000</span></td>
                    </tr>
                    <tr>
                                <td class="left  "><b>C2</b></td>
                                <td class=" ">28.478</td>
                    </tr>
                    <tr>
                                <td class="left  dark "><b>C3</b></td>
                                <td class=" dark "></td>
                    </tr>
                    <tr>
                                <td class="left bottom "><b>Total</b></td>
                                <td class="bottom "><b>180584.668</b></td>
                    </tr>
            </tbody>
        </table>
    </div>
</div>
                        <div id="pageContent" class="content-with-sidebar">
                    <div class="second-level-menu">
<ul class="second-level-menu-list">
        <li class="current selectedLava"><a
                                        href="/contest/1235">Problems</a></li>
        <li><a
                                        href="/contest/1235/submit">Submit Code</a></li>
        <li><a
                                        href="/contest/1235/my">My Submissions</a></li>
        <li><a
                                        href="/contest/1235/status">Status</a></li>
        <li><a
                                        href="/contest/1235/standings">Standings</a></li>
        <li><a
                                        href="/contest/1235/customtest">Custom Invocation</a></li>
</ul>
</div>

    <style>
        .input-output-copier {
            font-size: 1.2rem;
            float: right;
            color: #888 !important;
            cursor: pointer;
            border: 1px solid rgb(185, 185, 185);
            padding: 3px;
            margin: 1px;
            line-height: 1.1rem;
            text-transform: none;
        }

        .input-output-copier:hover {
            background-color: #def;
        }

        .test-explanation textarea {
            width: 100%;
            height: 1.5em;
        }
    </style>

<div class="problemindexholder" problemindex="A1">
        <div class="ttypography"><div class="problem-statement"><div class="header"><div class="title">A1. Shuffled Images</div><div class="time-limit"><div class="property-title">time limit per test</div>1 second</div><div class="memory-limit"><div class="property-title">memory limit per test</div>256 megabytes</div><div class="input-file"><div class="property-title">input</div>standard input</div><div class="output-file"><div class="property-title">output</div>standard output</div></div><div><p>In this problem, you have to restore the image, if it was previously divided into square fragments of $$$p \times p$$$ pixels, which were shuffled randomly. You are given a set of images, each has a size of $$$512 \times 512$$$ pixels. Divide each image into $$$m \times m$$$ square fragments of $$$p \times p$$$ pixels ($$$m = 512 / p$$$) and rearrange them to restore the original image. It is guaranteed that all original images are regular photos (perhaps with some minor vertical/horizontal scales).</p><p>For each image, you can get from 0 to 100 points. The score for the image is equal to the ratio of correctly defined &quot;edges&quot; between the images. Here, by an &quot;edge&quot; we call a horizontal or vertical segment of length $$$p$$$ pixels, which separates two adjacent fragments along the side. An &quot;edge&quot; is defined correctly if output contains the edge the answer (the order of the fragments &quot;bottom-top&quot; or &quot;left-right&quot; matters). The total number of such &quot;edges&quot; is $$$2\cdot m \cdot (m - 1) = k$$$. Formally, the score for the image will be $$$100 \cdot a / k$$$, where $$$a$$$ is the number of correct &quot;edges&quot;. Points for the images in a test are summarized. If you do not provide an answer to the image, then the score for it is $$$0$$$.</p><p>Problem A contains tests with parameters $$$p = 64$$$, $$$m = 8$$$, $$$k = 112$$$. Problem B contains tests with parameters $$$p = 32$$$, $$$m = 16$$$, $$$k = 480$$$. Problem C contains tests with parameters $$$p = 16$$$, $$$m = 32$$$, $$$k = 1984$$$. Each problem is divided into three subproblems.</p></div><div class="input-specification"><div class="section-title">Input</div><p>The archive with data is available at the link <a href="https://assets.codeforces.com/rounds/1235/shuffled-images-data.zip">https://assets.codeforces.com/rounds/1235/shuffled-images-data.zip</a>, <a href="https://icpc.sgu.ru/files/shuffled-images-data.zip">https://icpc.sgu.ru/files/shuffled-images-data.zip</a> or <a href="https://yadi.sk/d/BmnFhkaD1Vy4vA">https://yadi.sk/d/BmnFhkaD1Vy4vA</a>. The data is divided into three folders: <span class="tex-font-style-tt">data_train</span>, <span class="tex-font-style-tt">data_test1_blank</span>, and <span class="tex-font-style-tt">data_test2_blank</span>. Each of the folders contains three subfolders: <span class="tex-font-style-tt">64</span>, <span class="tex-font-style-tt">32</span> and <span class="tex-font-style-tt">16</span>. Each of the subfolders contains a set of png-files with fragment sizes $$$64$$$, $$$32$$$ and $$$16$$$ respectively. You need to process all images (or any subset of them) and send a text file containing information about the permutations of fragments for each of the files.</p><p>Files in the <span class="tex-font-style-tt">data_train</span> folder are intended for training. This folder contains additional files <span class="tex-font-style-tt">data_train_64_answers.txt</span>, <span class="tex-font-style-tt">data_train_32_answers.txt</span> and <span class="tex-font-style-tt">data_train_16_answers.txt</span> containing the correct answers for all images in corresponding subfolder. Additionally, this folder contains subfolders <span class="tex-font-style-tt">64-sources</span>, <span class="tex-font-style-tt">32-sources</span> and <span class="tex-font-style-tt">16-sources</span>, which contains source images for the corresponding set.</p><p>Images in the <span class="tex-font-style-tt">data_test1_blank</span> folder are intended for preliminary testing, images in the <span class="tex-font-style-tt">data_test2_blank</span> folder are intended for final (system) testing.</p></div><div class="output-specification"><div class="section-title">Output</div><p>A submission is a text file with the following contents: </p><pre class="verbatim"><br />file_name_1<br />permutation_1<br />file_name_2<br />permutation_2<br />...<br />file_name_n<br />permutation_n<br /></pre><p>where <span class="tex-font-style-tt">file_name_i</span> is the name of the image file for which the answer is provided, and <span class="tex-font-style-tt">permutation_i</span> is the permutation of integers from $$$0$$$ to $$$m^2 - 1$$$. Enumerate the fragments in the image from left to right, top to bottom. The $$$i$$$-th number in the permutation should be equal to the fragment index of the given (i.e., shuffled) image, which is located in the $$$i$$$-th fragment of the resulting image.</p><p>All filenames in the text file sent out must be different and correspond to the image filenames in the corresponding folder. It is allowed not to provide answers for one or more images.</p><p>Problems A1, B1 and C1 contains tests from the <span class="tex-font-style-tt">data_train</span> folder with fragment sizes $$$64$$$, $$$32$$$ and $$$16$$$ respectively. Answers to the training data are open to you, but you can send your answers if you want. These tasks are only needed to test your solutions. These problems will be hidden before official system testing.</p><p>Problems A2, B2 and C2 contains tests from the <span class="tex-font-style-tt">data_test1_blank</span> folder with fragment sizes $$$64$$$, $$$32$$$ and $$$16$$$ respectively. Your solutions will be checked and evaluated immediately after each submission. Use these problems to check and estimate the quality of your approach. These problems will be hidden before the official system testing.</p><p>Problems A3, B3 and C3 contains tests from the <span class="tex-font-style-tt">data_test2_blank</span> folder with fragment sizes $$$64$$$, $$$32$$$ and $$$16$$$ respectively, by which the winners will be determined (official system tests). Your solutions will not be judged during the contest, but the format will be checked. A properly formatted solution will receive 0 points during the contest. After the contest, for each participant we will use the <span class="tex-font-style-it">last</span> correctly formatted (0 points) submission on problems A3, B3 and C3 to evaluate the quality of the solution. <span class="tex-font-style-bf">These values will be used to determine the winners</span>.</p></div></div><p>  </p></div>
</div>


<script type="text/javascript">
    $(document).ready(function () {
        function endsWith(string, suffix) {
            return string.indexOf(suffix, string.length - suffix.length) !== -1;
        }

        var inputFileDiv = $("div.input-file");
        var inputFile = inputFileDiv.text();
        var outputFileDiv = $("div.output-file");
        var outputFile = outputFileDiv.text();

        if (!endsWith(inputFile, "standard input")
                && !endsWith(inputFile, "standard input")) {
            inputFileDiv.attr("style", "font-weight: bold");
        }

        if (!endsWith(outputFile, "standard output")
                && !endsWith(outputFile, "standard output")) {
            outputFileDiv.attr("style", "font-weight: bold");
        }

        var titleDiv = $("div.header div.title");



        String.prototype.replaceAll = function (search, replace) {
            return this.split(search).join(replace);
        };

        $(".sample-test .title").each(function() {
            var preId = ("id" + Math.random()).replaceAll(".", "0");
            var cpyId = ("id" + Math.random()).replaceAll(".", "0");

            $(this).parent().find("pre").attr("id", preId);
            var $copy = $("<div title='Copy' data-clipboard-target='#" + preId + "' id='" + cpyId + "' class='input-output-copier'>Copy</div>");
            $(this).append($copy);

            var clipboard = new Clipboard('#' + cpyId, {
                text: function(trigger) {
                    return Codeforces.filterClipboardText(document.querySelector('#' + preId).innerText);
                }
            });

            var isInput = $(this).parent().hasClass("input");

            clipboard.on('success', function(e) {
                if (isInput) {
                    Codeforces.showMessage("The example input has been copied into the clipboard");
                } else {
                    Codeforces.showMessage("The example output has been copied into the clipboard");
                }
                e.clearSelection();
            });
        });

        autosize($('.test-explanation textarea'));

    });
</script>

                </div>
        </div>
            <br style="clear: both;"/>
            <div id="footer">
                <div><a href="https://codeforces.com/">Codeforces</a> (c) Copyright 2010-2019 Mike Mirzayanov</div>
                <div>The only programming contests Web 2.0 platform</div>
                    <div>Server time: <span class="format-timewithseconds" data-locale="en">Oct/01/2019 14:01:31</span> (e2).</div>
                    <div>Desktop version, switch to <a rel="nofollow" class="switchToMobile" href="?mobile=true">mobile version</a>.</div>
                <div class="smaller"><a href="/privacy">Privacy Policy</a></div>

                    <div style="margin-top: 25px;">
                        Supported by
                    </div>
                    <div style="margin-top: 8px; padding-bottom: 20px; position: relative; left: 10px;">
                        <a href="https://telegram.org/"><img style="margin-right: 2em; width: 60px;" src="//sta.codeforces.com/s/88254/images/telegram-100x100.png" alt="Telegram" title="Telegram"/></a>
                        <a href="http://ifmo.ru/en/"><img style="width: 120px;" src="//sta.codeforces.com/s/88254/images/itmo_small_en-logo.png" alt="ИТМО" title="ИТМО"/></a>
                    </div>
            </div>
        <script type="text/javascript">
            $(function() {
                $(".switchToMobile").click(function() {
                    Codeforces.redirect(Codeforces.updateUrlParameter(document.location.href, "mobile", "true"));
                    return false;
                });
                $(".switchToDesktop").click(function() {
                    Codeforces.redirect(Codeforces.updateUrlParameter(document.location.href, "mobile", "false"));
                    return false;
                });
            });
        </script>
    <script type="text/javascript">
        $(document).ready(function () {
            if ($(window).width() < 1600) {
                $('.button-up').css('width', '30px').css('line-height', '30px').css('font-size', '20px');
            }

            if ($(window).width() >= 1200) {
                $ (window).scroll (function () {
                    if ($ (this).scrollTop () > 100) {
                        $ ('.button-up').fadeIn();
                    } else {
                        $ ('.button-up').fadeOut();
                    }
                });

                $('.button-up').click(function () {
                    $('body,html').animate({
                        scrollTop: 0
                    }, 500);
                    return false;
                });

                $('.button-up').hover(function () {
                    $(this).animate({
                        'opacity':'1'
                    }).css({'background-color':'#e7ebf0','color':'#6a86a4'});
                }, function () {
                    $(this).animate({
                        'opacity':'0.7'
                    }).css({'background':'none','color':'#d3dbe4'});;
                });
            }
            Codeforces.focusOnError();
        });
    </script>

        <div class="userListsFacebox" style="display:none;">
            <div style="padding: 0.5em; width: 600px; max-height: 200px; overflow-y: auto">
<div class="datatable"
     
     style="background-color: #E1E1E1; padding-bottom: 3px;">
            <div class="lt">&nbsp;</div>
            <div class="rt">&nbsp;</div>
            <div class="lb">&nbsp;</div>
            <div class="rb">&nbsp;</div>

            <div style="padding: 4px 0 0 6px;font-size:1.4rem;position:relative;">
                User lists

                <div style="position:absolute;right:0.25em;top:0.35em;">
                    <span style="padding:0;position:relative;bottom:2px;" class="rowCount"></span>

                    <img class="closed" src="//sta.codeforces.com/s/88254/images/icons/control.png"/>

                    <span class="filter" style="display:none;">
                        <img class="opened" src="//sta.codeforces.com/s/88254/images/icons/control-270.png"/>
                        <input style="padding:0;position:relative;bottom:2px;border:1px solid #aaa;height:17px;font-size:1.3rem;"/>
                    </span>
                </div>
            </div>
            <div style="background-color: white;margin:0.3em 3px 0 3px;position:relative;">
            <div class="ilt">&nbsp;</div>
            <div class="irt">&nbsp;</div>
            <table class="">
                    <thead>
                    <tr>
                        <th>Name</th>
                    </tr>
                    </thead>
                    <tbody>
                    </tbody>
            </table>
            </div>
        </div>
    <script type="text/javascript">
        $(document).ready(function () {
                // Create new ':containsIgnoreCase' selector for search
                jQuery.expr[':'].containsIgnoreCase = function(a, i, m) {
                    return jQuery(a).text().toUpperCase()
                            .indexOf(m[3].toUpperCase()) >= 0;
                };

                if (window.updateDatatableFilter == undefined) {
                    window.updateDatatableFilter = function(i) {
                        var parent = $(i).parent().parent().parent().parent();
                        $("tr.no-items", parent).remove();
                        $("tr", parent).hide().removeClass('visible');
                        var text = $(i).val();
                        if (text) {
                            $("tr" + ":containsIgnoreCase('" + text + "')", parent).show().addClass('visible');
                        } else {
                            parent.find(".rowCount").text("");
                            $("tr", parent).show().addClass('visible');
                        }

                        var found = false;
                        var visibleRowCount = 0;
                        $("tr", parent).each(function () {
                            if (!found) {
                                if ($(this).find("th").size() > 0) {
                                    $(this).show().addClass('visible');
                                    found = true;
                                }
                            }
                            if ($(this).hasClass('visible')) {
                                visibleRowCount++;
                            }
                        });
                        if (text) {
                            parent.find(".rowCount").text("Matches: " + (visibleRowCount - (found ? 1 : 0)));
                        }
                        if (visibleRowCount == (found ? 1 : 0)) {
                            $("<tr class='no-items visible'><td style=\"text-align:left;\"colspan=\"32\">No items<\/td><\/tr>").appendTo($(parent).find('table'));
                        }
                        $(parent).find("tr td").removeClass("dark");
                        $(parent).find("tr.visible:odd td").addClass("dark");
                    }

                    $(".datatable .closed").click(function () {
                        var parent = $(this).parent();
                        $(this).hide();
                        $(".filter", parent).fadeIn(function () {
                            $("input", parent).val("").focus().css("border", "1px solid #aaa");
                        });
                    });

                    $(".datatable .opened").click(function () {
                        var parent = $(this).parent().parent();
                        $(".filter", parent).fadeOut(function () {
                            $(".closed", parent).show();
                            $("input", parent).val("").each(function () {
                                window.updateDatatableFilter(this);
                            });
                        });
                    });

                    $(".datatable .filter input").keyup(function(e) {
                        window.updateDatatableFilter(this);
                        e.preventDefault();
                        e.stopPropagation();
                    });

                    $(".datatable table").each(function () {
                        var found = false;
                        $("tr", this).each(function () {
                            if (!found && $(this).find("th").size() == 0) {
                                found = true;
                            }
                        });
                        if (!found) {
                            $("<tr class='no-items visible'><td style=\"text-align:left;\"colspan=\"32\">No items<\/td><\/tr>").appendTo(this);
                        }
                    });

                    // Applies styles to datatables.
                    $(".datatable").each(function () {
                        $(this).find("tr:first th").addClass("top");
                        $(this).find("tr:last td").addClass("bottom");
                        $(this).find("tr:odd td").addClass("dark");
                        $(this).find("tr td:first-child, tr th:first-child").addClass("left");
                        $(this).find("tr td:last-child, tr th:last-child").addClass("right");
                    });

                    $(".datatable table.tablesorter").each(function () {
                        $(this).bind("sortEnd", function () {
                            $(".datatable").each(function () {
                                $(this).find("th, td")
                                    .removeClass("top").removeClass("bottom")
                                    .removeClass("left").removeClass("right")
                                    .removeClass("dark");
                                $(this).find("tr:first th").addClass("top");
                                $(this).find("tr:last td").addClass("bottom");
                                $(this).find("tr:odd td").addClass("dark");
                                $(this).find("tr td:first-child, tr th:first-child").addClass("left");
                                $(this).find("tr td:last-child, tr th:last-child").addClass("right");
                            });
                        });
                    });
                }
        });
    </script>
            </div>
        </div>
        <script type="application/javascript">
            $(function() {
                $(".userListMarker").click(function() {
                    $.post("/data/lists", {action: "findTouched"}, function(json) {
                        Codeforces.facebox(".userListsFacebox");
                        var tbody = $("#facebox tbody");
                        tbody.empty();
                        for (var i in json) {
                            tbody.append(
                                    $("<tr></tr>").append(
                                            $("<td></td>").attr("data-readKey", json[i].readKey).text(json[i].name)
                                    )
                            );
                        }
                        Codeforces.updateDatatables();
                        tbody.find("td").css("cursor", "pointer").click(function() {
                            document.location = Codeforces.updateUrlParameter(document.location.href, "list", $(this).attr("data-readKey"));
                        });
                    }, "json");
                });
            });
        </script>
</div>
    <script type="application/javascript">
        if ('serviceWorker' in navigator && 'fetch' in window && 'caches' in window) {
            var parser = new UAParser();
            var browserName = parser.getBrowser().name;
            var browserVersion = parser.getBrowser().version;

            var supportedBrowser = false;
            var supportedBrowsers = {
                "Chrome": "76",
                "Firefox": "68",
                // "Edge": "18",
                "Safari": "12.1",
                "Opera": "63",
                "Yandex": "19.9"
            };

            for (var name in supportedBrowsers) {
                if (name === browserName && supportedBrowsers[name] <= browserVersion) {
                    supportedBrowser = true;
                }
            }

            if (supportedBrowser) {
                navigator.serviceWorker.register('/service-worker-88254.js')
                    .then(function (registration) {
                        console.log('Service worker registered');
                    })
                    .catch(function (error) {
                        console.log('Registration failed: ', error);
                    });
            } else {
                navigator.serviceWorker.getRegistrations().then(function(registrations) {
                    for (var i = 0; i < registrations.length; i++) {
                        registrations[i].unregister();
                    }
                });
            }
        }
    </script>
</body>
</html>
