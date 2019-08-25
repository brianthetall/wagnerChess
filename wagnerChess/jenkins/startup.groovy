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
				pip install --upgrade pip	      
			             pysh 'pip install -r requirements.txt'
       				     }
    		     }
				     

		dir("wagnerChess"){
		      println "running jenkins test script from wagnerChess/pytests"
		      sh 'jenkins/run_tests.sh'

    		}
	}

}
