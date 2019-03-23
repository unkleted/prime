#!/usr/bin/env perl

use strict;
use warnings;

my $number;
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

if ($number == 1) {
	print "One is not prime.\n";
	exit;
}
if ($number > 2 && $number % 2 == 0) {
	print "Even numbers larger than 2 aren't prime.\n";
	exit;
}
if ($number > 3 && $number % 3 == 0) {
	print "$number is divisible by 3.\n";
	exit;
}

my $root = $number ** .5;
for (my $n=5; $n<=$root; $n+=6) {
	if ($number % $n == 0) {
		print "$number is divisible by $n.  It is NOT prime.\n";
		exit;
	}
	my $m = $n+2;
	if ($number % $m == 0) {
		print "$number is divisible by $m.  It is NOT prime.\n";
		exit;
	}
}

print "$number IS PRIME!!!\n";
