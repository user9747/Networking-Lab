  # Create scheduler
  set ns [new Simulator]

  
  $ns color 1 darkmagenta
  $ns color 2 yellow
  $ns color 3 blue
  $ns color 4 green
  $ns color 5 black

  #Tracing simulation results
  set fin [open result.dat w]
  $ns trace-all $fin

  #Tracing for NAM(Network Animator)
  set nfin [open out.nam w]
  $ns namtrace-all $nfin
  # Create a node
  set n0 [$ns node]

  # Create another node
  set n1 [$ns  node]
  # Create TCP agent and attach to first node
  set tcp0 [new Agent/TCP]
  $ns attach-agent $n0 $tcp0

  # Create TCP receiver and attach to second node
  set tcp1 [new Agent/TCPSink]
  $ns attach-agent $n1 $tcp1
  # Connect both nodes with 1.5Mbps bandwidth, 5 milli seconds delay and DropTail queue. DropTail works according to FIFO pattern.
  $ns duplex-link $n0 $n1 1Mb 5ms DropTail

  # Connect tcp0 and tcp1 agents
  $ns connect $tcp0 $tcp1
	
  $tcp0 set fid_ 4
  $tcp1 set fid_ 2
  # Create a FTP object
  set ftp [new Application/FTP]
  # Attach ftp application with agent tcp0
   $ftp attach-agent $tcp0
   $ftp set fid_ 3
  # Schedule events
  $ns at 0.2 "$ftp start"
  $ns at 2.0 "$ftp stop"
  # Finish procedure to perform operation at the end of simulation

  proc finish { } {
  	# Mapping of global variable into local variable
  	global ns fin nfin
	  # Flush all buffers
	  $ns flush-trace
	  #close file objects
	  close $fin
	  close $nfin
	  #Execute nam process in background 
	  exec nam out.nam &
	  #Terminate current process
	  exit 0
  }
  $ns at 2.2 "finish"
  $ns run
