#!/usr/bin/env python
# -*- coding: utf-8 -*-

import languageIdentifier

languageIdentifier.load("/Users/jgraves/trigrams/")
print languageIdentifier.identify("This is a short english string?", 300, 300), "English"
print languageIdentifier.identify("ليل مواقع احبك موت,دردشة,شات,منتديات,احبك,منتدى,دلي", 300, 300), "Arabic"
print languageIdentifier.identify("La vitamina A o retinol es una vitamina o un calcio liposoluble; ayuda a la formación y mantenimiento de dientes sanos y tejidos blandos y óseo", 300, 300), "Spanish"
print languageIdentifier.identify("Á, ou A accent aigu, est un graphème utilisé dans les alphabets féringien, hongrois, islandais, slovaque et tchèque en tant que lettre et dans les alphabets", 300, 300), "French"
print languageIdentifier.identify("Первый Альтернативный Музыкальный Телеканал - альтернативная музыка, новости музыки, клипы, форум о музыке.", 300, 300), "Russian"
print languageIdentifier.identify("Die Übersetzung der Präposition à hängt stark von dem jeweiligen Kontext ab. Da im Französischen nicht dekliniert wird,", 300, 300), "German"
print languageIdentifier.identify("這是具有歷史意義的一部A 片（雖然不是我們的歷史～）; 有劇情（雖然我覺得A 片幹嘛要有劇情？哪個人看A 片會像看電影", 300, 300), "Chinese"
print languageIdentifier.identify("ラテン文字（アルファベット）の1番目の文字。小文字は a 。ギリシャ文字のΑ（アルファ）に由来し、キリル文字のАに相当する ... この文字が表す音素は原則として[a]（非円唇前舌広母音）もしくは[ɑ]（非円唇後舌広母音", 300, 300), "Japanese"
print languageIdentifier.identify("lettera dell'alfabeto latino e italiano e anche nella maggior parte degli alfabeti derivanti da quello fenicio.", 300, 300), "Italian"
print languageIdentifier.identify("선박 운송 전문업체, 서비스 포트정보와 해외지사 소개, 운항스케쥴, 고객 서비스 제공.", 300, 300), "Korean"
print languageIdentifier.identify("Det gemena a:et finns utformat i två versioner (allografer): det så kallade envånings-a:et med en våning (ɑ) och det så kallade tvåvånings-a:et med två", 300, 300), "Swedish"
print languageIdentifier.identify("A ni herufi ya kwanza katika alfabeti ya Kilatini ambayo ni pia mwandiko wa Kiswahili cha kisasa. Asili yake ni Alfa ya Kigiriki.", 300, 300), "Swahili"
print languageIdentifier.identify("Å je písmeno v abecedě některých jazyků (švédština, finština, dánština, norština, severofríština, valonština, chamorro, istro-románské jazyky), kde označuje", 300, 300), "Czech"
print languageIdentifier.identify("What is a paradigm? In my own words, a paradigm is a belief system. It can be a personal belief system, or one held by a mass number of people, or even the whole world. Such a belief system is so entrenched in our minds as truth that it usually does not occur to us to question it. Therefore, many of us never even think that maybe this thought pattern needs updating. But, inevitably there are those that go against the common thought, and begin to challenge long held beliefs. More and more people begin to awaken, each individual begins to change their personal belief system, and the phenomenon that occurs as this old belief system comes tumbling down is often referred to as a paradigm shift", 300, 300), "English"
print languageIdentifier.identify("旧Kの現Aは久しぶりの公演なのかwww RT @akb_rss: [倉持明日香] (初・ω・) ノ: さあ！ いよいよ Ａ6th初日です|q∀`*))★ 久しぶりの劇場公演。 楽しみすぎるっ (●´∀`●) ... http://bit.ly/chy8Ue #akb48", 300, 300), "Japanese"
print languageIdentifier.identify("自抽耳光 会在转化为 抽人耳光 这帮奴才 RT @haojinsong 湖北涉事警察自抽耳光道歉http://news.163.com/10/0726/00/6CFSTGNM00011229.html", 300, 300), "Chinese"
print languageIdentifier.identify("好人不当村长,好人当上也会被... RT @gzgy123: RT @global70: 劉巍律師關注白虎頭村 RT @CitizenRight: RT @yuanxinting: RT @liuweilawyers: 今天有消息传出，村长许坤被施酷刑，情况严重，请大家关注", 300, 300), "Chinese"
print languageIdentifier.identify("RT @WuyouLan 我一直以為我不是女士呢&gt;@thisisxiaoxie: @WuyouLan 俺一直以为你是女士呢！心里经常发言：介个女滴很、厉、害、呀！呵呵~~", 300, 300), "Chinese"
print languageIdentifier.identify("@haruca さわったりくちづけしたり、そりゃもうあーた（ry", 300, 300), "Japanese"
print languageIdentifier.identify("遅くまでお疲れ様です。これからの夕飯？美味しいものに巡り会える事をお祈りします(^^;; RT @tukeuchiessence @taruyajusuke 食べたい！食べたい！食べた〜い！こちらは演劇人祭舞台稽古終わりました〜", 300, 300), "Japanese"
print languageIdentifier.identify("今ならさいとうごぼう店いったことあることが自慢できるうう！ (#dommune live at http://ustre.am/dhFr )", 300, 300), "Japanese"
print languageIdentifier.identify("@tomozoushopフォローありがとうございます＾＾よろしくお願いします☆", 300, 300), "Japanese"
print languageIdentifier.identify("女子でピンクのテレキャスは、舐められまっせ！！(違う)", 300, 300), "Japanese"
print languageIdentifier.identify("", 300, 300), "BLANK"
