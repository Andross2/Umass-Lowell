#!/usr/bin/perl
use 5.10.0;
use warnings FATAL => 'all';

use File::Temp;
use File::Copy;
use IO::Handle;

sub scm_eval {
    my ($cmdline) = @_;
    my $tmpcmd = File::Temp->new;
    $tmpcmd->say($cmdline);
    my $tmpcode = File::Temp->new;
    copy("ps.rkt", $tmpcode) or die "Copy failed: $!";
    open(my $fh, '>>', $tmpcode);
    $fh->say('(define-namespace-anchor bottlenose-nsa)
(define bottlenose-ns (namespace-anchor->namespace bottlenose-nsa))
(eval (call-with-input-string (vector-ref (current-command-line-arguments) 0) read) bottlenose-ns)');
    my $result = `racket $tmpcode '(load "$tmpcmd")'`;
    chomp $result;
#    print "answer was ", $result, " ";
    return $result;
}

sub scm_equal {
    my ($e0, $e1) = @_;
    my $tmp = File::Temp->new;
    $tmp->say("(equal? $e0 $e1)");
    my $result = `racket -e '(load "$tmp")'`;
    chomp $result;
    return $result eq "#t";
}

use Test::Simple tests => 7;

ok(scm_equal(scm_eval("(proc1 3 4)"), 50), "(proc1 3 4) is 50");
ok(scm_equal(scm_eval("(proc2 5)"), 336), "(proc2 5) is 336");
ok(scm_equal(scm_eval("(proc3 6)"), 21), "(proc3 6) is 21");
ok(scm_equal(scm_eval("(proc4 5 12)"), 45), "(proc4 5 12) is 45");
ok(scm_equal(scm_eval("(proc5 10)"), 114), "(proc5 10) is 114");
ok(scm_equal(scm_eval("(proc6 10 20 30)"), 3000), "(proc6 10 20 30) is 3000");
ok(scm_equal(scm_eval("(proc6-star 10 20 30)"), 3000), "(proc6-star 10 20 30) is 3000");


