# -*- coding: utf-8 -*-

import ez_setup
ez_setup.use_setuptools()

from setuptools import setup, Extension

setup(
    name='languageIdentifier',
    version='1.0.1.6',
    license='MIT',
    author='Jeff Graves',
    author_email='decultured@gmail.com',
    description='Language Identification using unicode testing and trigram identification',
    zip_safe=False, # I'm not sure if it is egg safe so I'm erring on the side of caution.
    long_description=__doc__,
	ext_modules = [
		Extension('languageIdentifier', 
		[	"identifier/language_detector.cpp", 
			"identifier/language_database.cpp", 
			"identifier/language_sample.cpp", 
			"identifier/trigram.cpp", 
			"identifier/unicode_tester.cpp", 
			"identifier/murmur/murmur.cpp", 
			"identifier/unicode/utf8.c", 
		],
		depends=[
			"identifier/language_database.h", 
			"identifier/language_sample.h", 
			"identifier/trigram.h", 
			"identifier/unicode_tester.h", 
			"identifier/murmur/murmur.h", 
			"identifier/unicode/utf8.h", 
		],
		include_dirs=['identifier','identifier/murmur', 'identifier/unicode'],
		libraries=['z'],
		language='c++')
	],
    platforms='any',
    classifiers=[
        'Development Status :: Beta',
        'Intended Audience :: Developers',
        'License :: OSI Approved :: MIT License',
        'Operating System :: OS Independent',
        'Programming Language :: C++',
        'Topic :: Software Development',
        'Topic :: Software Development :: Libraries :: Python Modules'
    ],
	packages=[]
)
