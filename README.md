Python Language Detector
========================

Trigram-based language detection built in C++ and wrapped as a python module.

Built for speed and reliability as primary concerns, with some small accuracy sacrifices vs. similar algorithms. For the purpose it was built for, the accuracy still remains very high for even short sample texts.

Identification is performed through basic trigram lookups paired with unicode character set recognition. Performance is aided by custom hash tables using Murmur hash for fast lookups.

This is currently used in a large commercial database application in production, and has proven to be stable, reliable, and fast.

**MIT Licensed (MIT)** - Copyright (c) 2012 Jeffrey Graves
