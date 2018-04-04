#/usr/bin/env perl
use strict;
use warnings;

our $number;
if ($ARGV[0] && $ARGV[0] =~ /^\d+$/) {
    $number = $ARGV[0];
} else {
    while ( not defined $number) {
        print "What number? >";
        $number = <STDIN>;
        chomp $number;
        if ($number !~ /^\d+$/) {
            undef $number;
        }
    }
}

&factor(2);
&factor(3);

my $root = $number ** .5;
for (my $i=5; $i<=$root; $i+=6) {
	&factor($i);
	&factor($i+2);
}

if ($number > 2) {
	print $number;
}

sub factor {
	my $n = shift;
	while ($number % $n == 0) {
		print "$n ";
		$number /= $n;
	}
}