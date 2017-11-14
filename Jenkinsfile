pipeline {
    agent { label "linux || macosx || windows" }
    triggers {
        pollSCM 'H/5 * * * *'
    }
    stages {
        stage ('compile') {
            steps {
                dir ('src') {
                    sh 'CCACHE_BASEDIR="`pwd`" ; export CCACHE_BASEDIR; make -k -j4 || make'
                    sh 'echo "Are GitIgnores good after make? (should have no output below)"; git status -s || true'
                }
            }
        }
        stage ('test') {
            steps {
                dir ('src') {
                    sh 'CCACHE_BASEDIR="`pwd`" ; export CCACHE_BASEDIR; make test'
                    sh 'echo "Are GitIgnores good after make test? (should have no output below)"; git status -s || true'
                }
            }
        }
        stage ('self-check GSL parser') {
            steps {
                dir ('src') {
                    sh 'CCACHE_BASEDIR="`pwd`" ; export CCACHE_BASEDIR; make check'
                    sh 'echo "Are GitIgnores good after make check? (should have no output below)"; git status -s || true'
                }
            }
        }
    }
}
