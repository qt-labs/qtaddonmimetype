TEMPLATE = subdirs

module_src.subdir = $$IN_PWD/src
module_src.target = module_src

module_simpletest.file = simpletest/simpletest.pro
module_simpletest.target = module_simpletest
module_simpletest.depends = module_src

module_unittests.file = unittests/unittests.pro
module_unittests.target = module_unittests
module_unittests.depends = module_src

module_declarative_unittests.file = unittests/declarative/tst_declarative_mimetypes.pro
module_declarative_unittests.target = module_declarative_unittests
module_declarative_unittests.depends = module_src

exists(src/src.pro): SUBDIRS += module_src
exists(simpletest/simpletest.pro): SUBDIRS += module_simpletest
exists(unittests/unittests.pro): SUBDIRS += module_unittests
exists(unittests/declarative/tst_declarative_mimetypes.pro): SUBDIRS += module_declarative_unittests
