# forensictool-plugin-git
Plugin for search git repository in file system

Requirements: Qt5

## Build plugin for forensictool:
	
	$ ./build_lib.sh

## Build single app:

	$ ./build_app.sh
	
### run single app:

	$ ./bin/forensictool-git --help

	Task is search git-repository

	  Usage: ./bin/forensictool-git [OPTIONS] 

	  OPTIONS:

		-i <fullpath>      - input folder, required parameter
		-o <fullpath>      - output folder, required parameter
		-h/--help          - this help

	  Version: 0.3.0
	  Author(s): Evgenii Sopov <mrseakg@gmail.com>
	  License: MIT License

	$ ==========TaskSearchGitRepository::execute==========

	 * Debug mode: On
	 * InputFolder:  "../"
	 * OutputFolder:  "/home/sea-kg/forensictool.output" 

	/home/sea-kg/develop/forensictool/forensictool-plugin-git => git@github.com:forensictool/forensictool-plugin-git.git
	/home/sea-kg/develop/forensictool/forensictool-core => git@github.com:forensictool/forensictool-core.git
	/home/sea-kg/develop/forensictool/web => git@github.com:forensictool/web.git

	==========TaskSearchGitRepository::finish==========
