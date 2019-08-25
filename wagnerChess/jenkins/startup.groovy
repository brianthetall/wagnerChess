currentBuild.description = "branch: $branch"

env.pyenv = "/usr/local/bin/python3.6" // system python3.6

def gitclone() {

    //git url: "$backend", branch: "$branch", credentialsId: "$credid"
   dir('games/wagnerChess') {
       println "-git checkout games..."
       git url:"$games", branch: "$branch", credentialsId: "$credid"
   }

}

node('master'){
	stage ("gitclone") {
	      println "%DEPLOYDB-I-GITCL cloning git repo..."
	      gitclone()
        }	      

	stage("Build Env for Back and Front"){
		     println "%pip install running..."
		     dir('games/wagnerChess') {

		            // setup virtualenv
			    withPythonEnv('/usr/local/bin/python3.6') {
			    	pysh 'pip install --upgrade pip'
				pysh 'ls -alh'
			        pysh 'cd wagnerChess && pip install -r requirements.txt'
				pysh 'pwd  && ls -alht && cd jenkins && ./run_tests.sh'
				
				}
    		     }
				     
	}

}
