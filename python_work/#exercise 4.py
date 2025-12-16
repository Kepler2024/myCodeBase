#exercise 4.1
jobs = ["blowjob","rimjob","nipple play"]
for job in jobs:
    print (f"I like {job}.")
print ("I really like these jobs!")
print (max(jobs))

#exercise 4.11
jobs_copy = jobs[:]
jobs.append("drinking semen")
jobs_copy.append("face fuck")
print("\nMy favourite jobs are:")
for job_1 in jobs:
    print(job_1)
print("\nAgain, my favourite jobs are:")
for job_2 in jobs_copy:
    print(job_2)