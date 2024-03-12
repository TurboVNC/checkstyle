SCRIPTDIR=`dirname $0`

mkdir -p $SCRIPTDIR/checkstyle.report

if [ "$1" != "" ]; then
	FILES="$1"
else
	FILES='*.java'
	EXCLFILES=':!java/com/jcraft :!java/org/spf4j :!java/org/mindrot'
fi

git ls-files -- "$FILES" $EXCLFILES | while read file; do
	java -jar ~/.checkstyle/checkstyle-all.jar -c $SCRIPTDIR/sun_checks.xml $file >$SCRIPTDIR/checkstyle.report/`basename $file`.txt
done
