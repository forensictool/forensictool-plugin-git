# coex-plugin-task-searchgitrepo
Plugin for search git repository in file system

Requirements: Qt5

## Build plugin for coex:
	
	$ ./build_lib.sh

## Build single app:

	$ ./build_app.sh
	
### run single app:

	$ ./bin/coex-searchgitrepo --help

	Task is search git-repository

	  Usage: ./bin/coex-searchgitrepo [OPTIONS] 

	  OPTIONS:

		--input-folder <fullpath>       - required parameter
		--output-folder <fullpath>      - required parameter
		--help                          - this help

	  Version: 0.1.0
	  Author: Evgenii Sopov <mrseakg@gmail.com>

	$ ./bin/coex-searchgitrepo --input-folder ../ --output-folder ../output


	==========TaskSearchGitRepository::execute==========

	 * Debug mode: On
	 * InputFolder:  "../"
	 * OutputFolder:  "../output" 

	/home/sea-kg/develop/tusur-coex/coex-plugin-task-searchgitrepo => git@github.com:tusur-coex/coex-plugin-task-searchgitrepo.git
	/home/sea-kg/develop/tusur-coex/coex => git@github.com:tusur-coex/coex.git
	/home/sea-kg/develop/tusur-coex/coex-core => git@github.com:tusur-coex/coex-core.git
	/home/sea-kg/develop/tusur-coex/create-packages => git@github.com:tusur-coex/create-packages.git
	/home/sea-kg/develop/tusur-coex/create-packages/build/coex-plugin-task-searchgitrepo => https://github.com/tusur-coex/coex-plugin-task-searchgitrepo.git
	/home/sea-kg/develop/tusur-coex/create-packages/build/coex-plugin-detect-ubuntu => https://github.com/tusur-coex/coex-plugin-detect-ubuntu.git
	/home/sea-kg/develop/tusur-coex/coex-testdata => git@github.com:tusur-coex/coex-testdata.git
	/home/sea-kg/develop/tusur-coex/coex-plugin-detect-ubuntu => git@github.com:tusur-coex/coex-plugin-detect-ubuntu.git

	==========TaskSearchGitRepository::finish==========
